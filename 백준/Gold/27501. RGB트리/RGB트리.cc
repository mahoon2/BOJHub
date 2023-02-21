#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 500002

using namespace std;

vector<int> adj[MAX_N];
int rgb[MAX_N][3]; // R, G, B 순
int dp[MAX_N][3];
int reconstruct_color[MAX_N];
int n;

int solve(int prev, int here, int prev_color)
{
    // prev_color를 제외한 나머지 색으로
    // here을 칠했을 때의 최댓값을 반환

    int m = 0;
    for(int color=0; color<3; color++)
    {
        int& ret = dp[here][color];

        if(color == prev_color)
        {
            continue;
        }
        if(ret != -1)
        {
            m = max(m, ret);
            continue;
        }

        ret = 0 + rgb[here][color];

        for(int next: adj[here])
        {
            if(next == prev) continue;
            ret += solve(here, next, color);
        }
        m = max(m, ret);
    }

    return m;
}

void reconstruct(int prev, int here, int prev_color)
{
    int color = 0;
    if(prev_color == 0) color = 1;
//    cout << here << ": ";
    for(int i=0; i<3; i++)
    {
//        cout << dp[here][i] << " ";

        if(i == prev_color)
        {
            continue;
        }

        if(dp[here][i] > dp[here][color])
        {
            color = i;
        }
    }
//    cout << '\n';

    reconstruct_color[here] = color;
    for(int next: adj[here])
    {
        if(next == prev) continue;
        reconstruct(here, next, color);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int from, to;
    for(int i=0; i<n-1; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int r, g, b;
    for(int i=1; i<=n; i++)
    {
        cin >> r >> g >> b;
        rgb[i][0] = r;
        rgb[i][1] = g;
        rgb[i][2] = b;
    }
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1, -1) << '\n';
    reconstruct(0, 1, -1);
    for(int i=1; i<=n; i++)
    {
        if(reconstruct_color[i] == 0)
        {
            cout << "R";
        }
        else if(reconstruct_color[i] == 1)
        {
            cout << "G";
        }
        else if(reconstruct_color[i] == 2)
        {
            cout << "B";
        }
    }
    cout << '\n';

    return 0;
}