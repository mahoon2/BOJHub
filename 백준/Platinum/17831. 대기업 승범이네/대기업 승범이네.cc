#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()

#define MAX_N 200001

using ll = long long;
using ld = long double;

using namespace std;

int n;
vector<int> child[MAX_N];
int score[MAX_N];
ll dp[MAX_N][2];

ll solve(int here, bool isOk)
{
    ll& ret = isOk? dp[here][1]:dp[here][0];
    if(ret != -1) return ret;

    ret = 0;
    ll ret1, temp;

    // 아무것도 고르지 않을 경우
    for(auto& there: child[here])
    {
        ret += solve(there, true);
    }

    if(isOk)
    {
        ret1 = ret;
        for(auto& selected: child[here])
        {
            temp = ret1;
            ret1 += solve(selected, false) - solve(selected, true) + score[here]*score[selected];
            ret = max(ret, ret1);
            ret1 = temp;
        }
    }
    //cout << here << " " << isOk << " " << ret << '\n';

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    int temp;
    for(int i=2; i<=n; i++)
    {
        cin >> temp;
        child[temp].push_back(i);
    }

    for(int i=1; i<=n; i++)
    {
        cin >> score[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(1, true) << '\n';
    
    return 0;
}