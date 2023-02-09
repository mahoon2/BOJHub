#include <iostream>

using namespace std;

int m, l;
int slicable[1005];

int slice(int gap)
{
    int last_slice_idx = 0;
    int i = 1;
    int ret = 0;

    for(i; i<=m; i++)
    {
        if(slicable[i] - slicable[last_slice_idx] >= gap && l - slicable[i] >= gap)
        {
            last_slice_idx = i;
            ret++;
        }
    }
    
    return ret;
}

int solve(int q)
{
    int lo = 0; // TRUE
    int hi = l; // FALSE

    while(hi - lo != 1)
    {
        int mid = (lo + hi) / 2;
        if(slice(mid) >= q)
            lo = mid;
        else
            hi = mid;
    }

    return lo;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n;
    cin >> n >> m >> l;

    slicable[0] = 0;
    for(int i=1; i<=m; i++)
    {
        cin >> slicable[i];
    }
    slicable[m+1] = l;


    while(n--)
    {
        int q;
        cin >> q;

        cout << solve(q) << '\n';
    }

    return 0;
}