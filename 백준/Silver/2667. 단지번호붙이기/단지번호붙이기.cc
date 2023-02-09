#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, danji=0;
vector<int> danji_num;
int board[25][25] = {0};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x, int& sum)
{
	sum++;
	board[y][x] = 0;
	for(int i=0; i<4; i++)
	{
		int next_y = y+dy[i], next_x = x+dx[i];
		if(next_y<0 || next_y>=n || next_x<0 || next_x>=n)
			continue;
		if(board[next_y][next_x])
			dfs(next_y, next_x, sum);
	}
}

int main()
{
	string temp;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		for(int j=0; j<n; j++)
			if(temp[j] == '1')
				board[i][j] = 1;
	}
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(board[i][j])
			{
				int sum = 0;
				danji++;
				dfs(i, j, sum);
				danji_num.push_back(sum);
			}
	
	sort(danji_num.begin(), danji_num.end());
	cout << danji << '\n';
	for(int i=0; i<danji; i++)
		cout << danji_num[i] << '\n';
	return 0;
}