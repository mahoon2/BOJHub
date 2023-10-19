#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)v.size())
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=1; i<=n; i++)


#define MAX_N 50001

int n, k;
int sum[MAX_N];
int dp[4][50001];

int solve(int left, int idx)
{
    if(left == 0) return 0;
    int& ret = dp[left-1][idx];
    if(ret != -1) return ret;

    for(int i=idx; i<=n-left*k; i++)
    {
        ret = max(ret, sum[i+k]-sum[i]+solve(left-1, i+k));
    }

    return ret;
}

int a()
{
    for(int i=0; i<=n; i++)
    {
        dp[0][i] = 0;
    }

    for(int left=1; left<=3; left++)
    {
        dp[left][n-left*k] = sum[n-(left-1)*k]-sum[n-left*k]+dp[left-1][n-(left-1)*k];
        for(int i=n-left*k-1; i>=(3-left)*k; i--)
        {
            dp[left][i] = max(dp[left][i+1], sum[i+k]-sum[i]+dp[left-1][i+k]);
        }
    }

    return dp[3][0];
}
// 0 35 75 125 135 165 210 270
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    int temp;
    sum[0] = 0;
    rrep(i, n)
    {
        cin >> temp;
        sum[i] = sum[i-1] + temp;
    }

    cin >> k;
    memset(dp, -1, sizeof(dp));
    //cout << solve(3, 0) << '\n';
    cout << a() << '\n';

    return 0;
}