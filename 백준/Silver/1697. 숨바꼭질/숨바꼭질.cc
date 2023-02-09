#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int k;
int discovered[1000001];

int bfs(int start)
{
	queue<int> q;
	q.push(start);
	discovered[start] = 0;
	if(start == k) return 0;
	
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		int there[3] = {here-1, here+1, 2*here};
		for(int i=0; i<3; i++)
		{
			int temp = there[i];
			if(temp == k)
				return discovered[here]+1;
			if(temp < 0 || temp > 100000 || discovered[temp] != -1)
				continue;
			discovered[temp] = discovered[here]+1;
			q.push(temp);
		}
	}
}

int main()
{
	int n;
	memset(discovered, -1, sizeof(discovered));
	cin >> n >> k;
	cout << bfs(n) << '\n';
	return 0;
}