#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MAX_N 100003

typedef long long ll;

using namespace std;

int n;
vector<int> adj[MAX_N];
bool visited[MAX_N];
ll dp[MAX_N][3];

void dfs(int here, int& cnt)
{
    visited[here] = true;

    for(int next: adj[here])
    {
        if(next == n+1) cnt++;
        if(!visited[next])
        {
            dfs(next, cnt);
        }
    }
}

ll comb(int a, int b)
{
    // aCb 의 계산
    // 문제 조건 상 b <= 2

    ll& ret = dp[a][b];

    if(ret != -1) return ret;

    if(b == 0) return ret = 1;
    if(b == 1) return ret = static_cast<ll>(a);
    
    return ret = comb(a-1, b) + comb(a-1, b-1);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n;

    string outside, inside;
    cin >> outside;
    cin >> inside;

    bool outside_all_connected = true;
    if(outside[0] == '1')
    {
        adj[n].push_back(1);
        adj[1].push_back(n);
    }

    for(int i=0; i<n; i++)
    {
        if(outside[i] == '1')
        {
            if(i != 0)
            {
                adj[i].push_back(i+1);
                adj[i+1].push_back(i);
            }
        }
        else
        {
            outside_all_connected = false;
        }


        if(inside[i] == '1')
        {
            adj[i+1].push_back(n+1);
            adj[n+1].push_back(i+1);
        }
    }

    memset(visited, 0, sizeof(visited));
    memset(dp, -1, sizeof(dp));
    
    ll ret = 0;
    visited[n+1] = true;
    for(int next: adj[n+1])
    {
        if(!visited[next])
        {
            int cnt = 0;
            dfs(next, cnt);
            ret += comb(cnt, 2);

//            cout << cnt << " " << ret << '\n';
        }
    }
    
    if(outside_all_connected)
        cout << 2*ret+1 << '\n';
    else
        cout << ret << '\n';
    
    return 0;
}