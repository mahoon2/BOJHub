#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int ret = 0;
int h, w;
string board[103];
bool visited[103][103];
vector<pair<int,int>> door[30];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs()
{
	queue<pair<int,int>> q;
	memset(visited, false, sizeof(visited));
	
	for(int j=0; j<w+2; j++)
	{
		q.push(make_pair(0, j));
		q.push(make_pair(h+1, j));
	}

	for(int i=0; i<h+2; i++)
	{
		q.push(make_pair(i, 0));
		q.push(make_pair(i, w+1));
	}
	
	bool isUpdated = false;
	while(!q.empty())
	{
		pair<int,int>& here = q.front();
		q.pop();
		if(visited[here.first][here.second]) continue;
		
		visited[here.first][here.second] = true;
	//	cout << here.first << " " << here.second << '\n';
		
		for(int i=0; i<4; i++)
		{
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];
			if(ny < 0 || ny >= h+2 || nx < 0 || nx >= w+2 || board[ny][nx] == '*' || visited[ny][nx])
				continue;
			if('A' <= board[ny][nx] && board[ny][nx] <= 'Z')
				continue;
			if('a' <= board[ny][nx] && board[ny][nx] <= 'z')
			{
				int key = board[ny][nx] - 'a';
				for(pair<int,int>& p: door[key])
					board[p.first][p.second] = '.';
				board[ny][nx] = '.';
				isUpdated = true;
			}
			else if(board[ny][nx] == '$')
			{
				ret += 1;
				board[ny][nx] = '.';
			}
			q.push(make_pair(ny, nx));
		}
	}
	
	if(isUpdated)
	{
		bfs();
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		for(int i=0; i<30; i++)
			door[i].clear();
		
		cin >> h >> w;
		string temp;
		board[0] = board[h+1] = '.';
		for(int j=0; j<w+1; j++)
		{
			board[0] += '.';
			board[h+1] += '.';
		}
		
		for(int i=1; i<h+1; i++)
		{
			cin >> temp;
			board[i] = '.' + temp + '.';
			for(int j=0; j<w+2; j++)
				if('A' <= board[i][j] && board[i][j] <= 'Z')
					door[board[i][j]-'A'].push_back(make_pair(i, j));
		}
		cin >> temp;
		if(temp != "0")
		{
			for(int j=0; j<temp.length(); j++)
			{
				int key = temp[j] - 'a';
				for(pair<int,int> p: door[key])
					board[p.first][p.second] = '.';
			}
		}
		
		/*cout << '\n';
		for(int i=0; i<h; i++)
			cout << board[i] << '\n';
		cout << '\n';
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
				cout << board[i][j];
			cout << '\n';
		}
		cout << '\n';
		
		for(int i=0; i<26; i++)
			if(door[i].size() > 0)
				for(auto& p: door[i])
					cout << p.first << " " << p.second << '\n';*/
		
		ret = 0;
		bfs();
		cout << ret << '\n';
	}
	
	return 0;
}

/*
1
3 3
a**
*$A
***
0

답이 1이지만 0을 출력하는 문제

outOfBounds 에러*/