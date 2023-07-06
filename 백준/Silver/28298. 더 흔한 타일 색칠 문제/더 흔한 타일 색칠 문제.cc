#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m, k;
vector<string> inp;
int num = 0;

char solve(int y, int x)
{
    int ret[26];
    memset(ret, 0, sizeof(ret));

    for(int i=y; i<n; i+=k)
    {
        for(int j=x; j<m; j+=k)
        {
            ret[inp[i][j]-'A']++;
        }
    }

    int temp = 0;
    int reti;
    for(int i=0; i<26; i++)
    {
        if(temp < ret[i])
        {
            temp = ret[i];
            reti = i;
        }
    }

    num += (int)(n/k) * (int)(m/k) - temp;
    return (char)('A'+reti);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    inp = vector<string> (n);

    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
    }

    vector<vector<char>> ret (k, vector<char>(k));

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            ret[i][j] = solve(i, j);
        }
    }

    cout << num << '\n';

    for(int i=0; i<n/k; i++)
    {
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<m/k; j++)
            {
                for(int j=0; j<k; j++)
                {
                    cout << ret[i][j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}