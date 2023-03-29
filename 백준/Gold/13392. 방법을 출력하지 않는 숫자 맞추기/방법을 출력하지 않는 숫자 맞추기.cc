#include <iostream>
#include <string>
#include <cstring>

#define MOD 10

using namespace std;

int n;
int inp[2][10001];
int dp[10001][10];
// 감소는 무제한, 증가는 제한

int solve(int idx, int plus)
{
    int& ret = dp[idx][plus];
    if(ret != -1) return ret;

    int here = (inp[0][idx] + plus) % MOD;
    int& there = inp[1][idx];

    int plus_temp, minus_temp;
    if(here <= there)
    {
        plus_temp = there-here;
        minus_temp = 10-plus_temp;
    }
    else
    {
        minus_temp = here-there;
        plus_temp = 10-minus_temp;
    }

    if(idx == n-1)
    {
        ret = min(plus_temp, minus_temp);
    }
    else
    {
        ret = min(plus_temp+solve(idx+1, (plus+plus_temp)%MOD),
        minus_temp+solve(idx+1, plus));
    }

    //cout << idx << " " << plus << ": " << ret << '\n';
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    string temp;

    for(int i=0; i<2; i++)
    {
        cin >> temp;
        for(int j=0; j<n; j++)
        {
            inp[i][j] = temp[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    return 0;
}