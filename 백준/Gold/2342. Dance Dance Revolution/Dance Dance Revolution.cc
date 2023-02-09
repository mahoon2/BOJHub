#include <iostream>
#include <cstring>

using namespace std;

int n;
int inp[100001];
int dp[100001][5][5];
int power[5][5];

void power_calc()
{
    for(int i=0; i<5; i++)
        power[0][i] = 2;
    for(int i=1; i<5; i++)
        power[i][i] = 1;

    power[1][2] = power[1][4] = 3; power[1][3] = 4;
    power[2][1] = power[2][3] = 3; power[2][4] = 4;
    power[3][2] = power[3][4] = 3; power[3][1] = 4;
    power[4][1] = power[4][3] = 3; power[4][2] = 4;
}

int solve(int index, int lp, int rp)
{
    if(index == n) return 0;
    int& ret = dp[index][lp][rp];
    if(ret != -1) return ret;

    int there = inp[index];
    if(there == lp)
        return ret = solve(index+1, there, rp) + power[lp][there];
    else if(there == rp)
        return ret = solve(index+1, lp, there) + power[rp][there];
    else
        return ret = min(solve(index+1, there, rp) + power[lp][there],
        solve(index+1, lp, there) + power[rp][there]);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int data, i=0;

    while(true)
    {
        cin >> data;
        if(data == 0) break;
        inp[i++] = data;
    }
    n = i;
    memset(dp, -1, sizeof(dp));
    power_calc();

    cout << solve(0, 0, 0) << '\n';
    return 0;
}