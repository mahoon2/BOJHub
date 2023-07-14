#include <iostream>
#define INF 987654321

using namespace std;
int dp[2000002];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    bool ret;

    if(k <= 4)
    {
        if(n > k) ret = false;
        else ret = true;
    }
    else
    {
        for(int i=1; i<=4; i++)
        {
            dp[i] = i;
        }
        for(int i=5; i<=n; i++)
        {
            dp[i] = INF;
        }

        for(int i=4; i<=n; i++)
        {
            dp[i+1] = min(dp[i]+1, dp[i+1]);
            dp[i+int(i/2)] = min(dp[i]+1, dp[i+int(i/2)]);
        }

        if(dp[n] <= k) ret = true;
        else ret = false;
    }

    if(ret) cout << "minigimbob\n";
    else cout << "water\n";

    return 0;
}