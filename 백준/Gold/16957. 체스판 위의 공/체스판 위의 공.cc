#include <iostream>
#include <cstring>

#define MAX_N 502
using namespace std;

int r, c;
int board[MAX_N][MAX_N];
int cnt[MAX_N][MAX_N];
pair<int,int> dp[MAX_N][MAX_N];
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 4는 제자리 / 0 1 2 / 3 4 5 / 6 7 8 처럼 숫자 키패드 순
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 4는 제자리

pair<int,int> dfs(int y, int x)
{
    pair<int,int>& ret = dp[y][x];

    if(ret.first != -1 && ret.second != -1) return ret;

    int min_idx = -1;
    int min_num = board[y][x];

    for(int i=0; i<8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if(board[ny][nx] < min_num)
        {
            min_idx = i;
            min_num = board[ny][nx];
        }
    }

    if(min_idx == -1) return ret = make_pair(y, x);
    else return ret = dfs(y + dy[min_idx], x + dx[min_idx]);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> r >> c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> board[i][j];
            dp[i][j] = make_pair(-1, -1);
        }
    }

    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            pair<int,int> p = dfs(i, j);
            cnt[p.first][p.second]++;
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << cnt[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}