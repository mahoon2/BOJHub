#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int inp[100001];
int temp[100001];

bool check(int c)
{
    for(int i=0; i<c; i++)
        temp[i] = inp[i];
    sort(temp, temp+c);

    long long ret = 1;
    for(int i=0; i<c; i++)
    {
        if(ret < temp[i]) break;
        else ret += (long long)(temp[i]);
    }

    return ret >= (long long)k+1 ? true : false;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0; i<n; i++)
        {
            cin >> inp[i];
        }

        if(!check(n))
        {
            cout << -1 << '\n';
            continue;
        }
        
        int l = 0;
        int r = n;
        int mid;
        while(l+1 != r)
        {
            mid = (l+r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }

    return 0;
}