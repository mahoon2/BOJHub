#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
int grid[100][100];
bool visited[100][100] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void sol(int y, int x, int& color)
{
	if(visited[y][x] || y<0 || y>=n || x<0 || x>=n)
		return;
	
	if(color == grid[y][x])
	{
		visited[y][x] = true;
		for(int i=0; i<4; i++)
			sol(y+dy[i], x+dx[i], color);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	string s;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		for(int j=0; j<n; j++)
			if(s[j] == 'R')
				grid[i][j] = 0;
			else if(s[j] == 'G')
				grid[i][j] = 1;
			else if(s[j] == 'B')
				grid[i][j] = 2;
	}
	
	int not_yak = 0, yak=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(!visited[i][j])
            {
				sol(i, j, grid[i][j]);
				not_yak++;
            }
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(grid[i][j] == 1)
				grid[i][j] = 0;
	memset(visited, 0, sizeof(visited));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(!visited[i][j])
            {
				sol(i, j, grid[i][j]);
				yak++;
			}
	
	cout << not_yak << " " << yak << endl;
	return 0;
}