#include <iostream>
#define MAX_N 500001

using namespace std;

int inp[MAX_N], a[MAX_N], b[MAX_N];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
        a[i] = inp[i] + k*i;
        b[i] = inp[i] - k*i;
    }

    int ret = -987654321;
    int temp = a[0];

    for(int i=1; i<n; i++)
    {
        ret = max(ret, temp-a[i]);
        temp = max(temp, a[i]);
    }

    temp = b[n-1];
    for(int i=n-2; i>=0; i--)
    {
        ret = max(ret, temp-b[i]);
        temp = max(temp, b[i]);
    }

    cout << ret << '\n';

    return 0;
}