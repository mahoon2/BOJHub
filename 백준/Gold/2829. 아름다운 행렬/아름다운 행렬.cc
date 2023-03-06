#include <iostream>
#include <cstring>

#define MAX_N 402

using namespace std;

int n;
int psl[MAX_N][MAX_N];
int psr[MAX_N][MAX_N];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    memset(psl, 0, sizeof(psl));
    memset(psr, 0, sizeof(psr));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> psl[i][j];
            psr[i][j] = psl[i][j];
        }
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=n; j++)
        {
            psl[i][j] += psl[i-1][j-1];
        }
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<n; j++)
        {
            psr[i][j] += psr[i-1][j+1];
        }
    }

    int ret = -987654321;
    int temp;
    for(int size=2; size<=n; size++)
    {
        for(int i=1; i<=n-size+1; i++)
        {
            for(int j=1; j<=n-size+1; j++)
            {
                temp = (psl[i+size-1][j+size-1]-psl[i-1][j-1]) -
                (psr[i+size-1][j]-psr[i-1][j+size]);
                ret = max(ret, temp);
            }
        }
    }
    cout << ret << '\n';

    return 0;
}