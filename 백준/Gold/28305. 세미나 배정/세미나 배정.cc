#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 200001

using namespace std;

int n, t;
int inp[MAX_N];
int temp[MAX_N];

bool solve(int k)
{
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<k; i++)
    {
        temp[i] = max(t, inp[i]);
    }

    for(int i=k; i<n; i++)
    {
        if(temp[i-k] >= inp[i]) return false;
        if(inp[i]-(t-1) > temp[i-k]) temp[i] = inp[i];
        else temp[i] = temp[i-k] + t;
    }

    return true;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> t;

    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
    }

    sort(inp, inp+n);

    int hi = n; // True
    int lo = 0; // False
    int mid;

    while(lo + 1 != hi)
    {
        mid = (hi + lo) / 2;
        if(solve(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    cout << hi << '\n';

    return 0;
}