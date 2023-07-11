#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define all(v) v.begin(), v.end()

using namespace std;

int n, m, k;
int inp[100002];
int cnt[1000002];
vector<array<int,3>> queries;
vector<array<int,2>> ret;

bool query_comp(array<int,3>& a, array<int,3>& b)
{
    if((a[0]/k) == (b[0]/k))
    {
        return a[1] < b[1];
    }
    else return (a[0]/k) < (b[0]/k);
}

bool ret_comp(array<int,2>& a, array<int,2>& b)
{
    return a[1] < b[1];
}

void solve()
{
    int cnt_ret = 0;
    memset(cnt, 0, sizeof(cnt));

    int prev_l = queries[0][0];
    int prev_r = queries[0][1];
    for(int i=prev_l; i<=prev_r; i++)
    {
        if(cnt[inp[i]]++ == 0) cnt_ret++;
    }
    ret[0] = {cnt_ret, queries[0][2]};

    for(int i=1; i<m; i++)
    {
        auto [left, right, query_idx] = queries[i];

        while(prev_l < left)
        {
            if(--cnt[inp[prev_l++]] == 0) cnt_ret--;
        }
        while(left < prev_l)
        {
            if(cnt[inp[--prev_l]]++ == 0) cnt_ret++;
        }
        while(prev_r < right)
        {
            if(cnt[inp[++prev_r]]++ == 0) cnt_ret++;
        }
        while(right < prev_r)
        {
            if(--cnt[inp[prev_r--]] == 0) cnt_ret--;
        }

        ret[i] = {cnt_ret, query_idx};
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> inp[i];
    }
    k = sqrt(n);

    cin >> m;
    queries = vector<array<int,3>> (m);
    for(int i=0; i<m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }
    sort(all(queries), query_comp);

    ret = vector<array<int,2>> (m);
    solve();
    sort(all(ret), ret_comp);
    for(auto r: ret)
    {
        cout << r[0] << '\n';
    }

    return 0;
}