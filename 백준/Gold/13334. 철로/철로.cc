#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, d;
bool visited[100001];
pair<int,int> pos[100001];
priority_queue<int> pq;

int solve()
{
	int ret = 0;
	int s = -100000000;
	int e = s + d;
	for(int i=0; i<n; i++)
	{
		if(pos[i].first - pos[i].second > d) continue;
		if(s <= pos[i].second && pos[i].first <= e)
			pq.push(-pos[i].second);
		else
		{
			e = pos[i].first;
			s = e - d;
			pq.push(-pos[i].second);
			
			while(!pq.empty())
			{
				if(-pq.top() < s)
					pq.pop();
				else
					break;
			}
		}
		ret = max(ret, (int)pq.size());
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	int s, e;
	for(int i=0; i<n; i++)
	{
		cin >> s >> e;
		if(s < e)
			pos[i] = make_pair(e, s);
		else
			pos[i] = make_pair(s, e);
	}
	cin >> d;
	sort(pos, pos+n);
	
	memset(visited, 0, sizeof(visited));
	cout << solve() << '\n';
	return 0;
}