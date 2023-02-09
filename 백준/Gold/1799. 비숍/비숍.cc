#include <iostream>

using namespace std;

int n, ret[2] = {0, 0};
int board[10][10];
bool rdused[20] = {false, };

void solve(int ld_index, int cnt, int& color)
{
    if(ld_index == 2*n-color)
    {
        ret[color] = max(ret[color], cnt);
        return;
    }

    int y_minus_x = 1 - n + ld_index;
    int y, x;
    if(y_minus_x <= 0)
    {
        y = 0;
        x = -y_minus_x;
    }
    else
    {
        y = y_minus_x;
        x = 0;
    }

    while(0 <= y && y <= n-1 && 0 <= x && x <= n-1)
    {
        int rd_index = y+x;
        if(board[y][x] && !rdused[rd_index])
        {
            rdused[rd_index] = true;
            solve(ld_index+2, cnt+1, color);
            rdused[rd_index] = false;
        }
        y++; x++;
    }

    solve(ld_index+2, cnt, color);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    int color=0;
    solve(0, 0, color);
    color=1;
    solve(1, 0, color);
    cout << ret[0] + ret[1] << '\n';
    return 0;
}