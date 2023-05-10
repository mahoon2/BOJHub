#include <iostream>
#include <cstring>
#define MAX_N 1025

using namespace std;

int n;
int inp[MAX_N][MAX_N];
int ret[MAX_N][MAX_N];
int sum[MAX_N];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    memset(ret, -1, sizeof(ret));
    memset(sum, 0, sizeof(sum));

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            cin >> inp[i][j];
            inp[j][i] = inp[i][j];
        }

        int min_idx = -1;
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(min_idx == -1 || inp[i][j] < inp[i][min_idx])
            {
                min_idx = j;
            }
        }
        ret[i][min_idx] = ret[min_idx][i] = 1;
        // cout << i << " " << min_idx << '\n';
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(ret[i][j] != -1) continue;
            for(int k=1; k<=n; k++)
            {
                if(i == k || j == k) continue;
                if(inp[i][j] == inp[i][k] + inp[k][j])
                {
                    ret[i][j] = ret[j][i] = 0;
                    break;
                }
            }

            if(ret[i][j] != 0)
            {
                ret[i][j] = ret[j][i] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(ret[i][j] == 1) sum[i]++;
        }
        cout << sum[i] << " ";
        
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(ret[i][j] == 1) cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}