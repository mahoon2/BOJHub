#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;

using namespace std;

int problems[5];
vector<int> hard[5];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    FOR(i, 5)
    {
        cin >> problems[i];
    }

    int temp1, temp2;
    FOR(i, n)
    {
        cin >> temp1 >> temp2;
        hard[temp1-1].push_back(temp2);
    }

    FOR(i, 5)
    {
        sort(all(hard[i]));
    }

    int ret = 0;
    FOR(i, 5)
    {
        if(i != 0 && problems[i]) ret += 60;
        FOR(j, problems[i])
        {
            if(j == 0) ret += hard[i][j];
            else ret += 2*hard[i][j] - hard[i][j-1];
        }
    }
    cout << ret << '\n';
    
    return 0;
}