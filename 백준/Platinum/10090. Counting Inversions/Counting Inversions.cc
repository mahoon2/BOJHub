#include <iostream>

#define MAX_N 1000001

using namespace std;

int n;
int inp[MAX_N];
int temp[MAX_N];
long long ret = 0;

void mergeSort(int start, int end, int* a, int* b)
{
    // a가 주 배열, b가 보조 배열
    if(start == end) return;

    int mid = (start+end) / 2;
    mergeSort(start, mid, b, a);
    mergeSort(mid+1, end, b, a);

    int l = start;
    int r = mid+1;
    int cnt = start;

    while(l <= mid && r <= end)
    {
        if(a[l] <= a[r]) b[cnt++] = a[l++];
        else
        {
            b[cnt++] = a[r++];
            ret = ret + (long long)(mid-l+1);
        }
    }

    while(l <= mid) b[cnt++] = a[l++];
    while(r <= end) b[cnt++] = a[r++];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
        temp[i] = inp[i];
    }

    mergeSort(0, n-1, inp, temp);
    /*for(int i=0; i<n; i++)
        cout << temp[i] << " ";
    cout << '\n';*/
    cout << ret << '\n';

    return 0;
}