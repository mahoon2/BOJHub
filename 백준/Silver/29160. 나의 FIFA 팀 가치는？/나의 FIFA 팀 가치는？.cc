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
int n, k;
priority_queue<int> pq[12];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> k;
    int temp1, temp2;
    FOR(i, n)
    {
        cin >> temp1 >> temp2;
        pq[temp1].push(temp2);
    }

    int ret = 0;
    FOR(i, k+1)
    {
        for(int j=1; j<=11; j++)
        {
            if(pq[j].empty()) continue;
            if(i == k)
            {
                ret += pq[j].top();
            }
            else
            {
                pq[j].push(pq[j].top()-1);
                pq[j].pop();
            }
        }
    }
    cout << ret << '\n';
    
    return 0;
}