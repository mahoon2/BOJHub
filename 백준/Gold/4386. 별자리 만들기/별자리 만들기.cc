#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_V 101

using namespace std;

int n;
vector<pair<double, int>> adj[MAX_V];

double dist(double dx, double dy)
{
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

double prim()
{
	double ret = 0;
	priority_queue<pair<double,int>> pq;
	vector<bool> visited(n, false);
	pq.push(make_pair(0.0, 0));
	
	while(!pq.empty())
	{
		double dist = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		if(visited[here]) continue;
		visited[here] = true;
		ret += dist;
		
		for(auto next_pair: adj[here])
		{
			double next_dist = next_pair.first;
			int next = next_pair.second;
			if(!visited[next])
				pq.push(make_pair(-next_dist, next));
		}
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	vector<pair<double, double>> poses(n);
	double x, y;
	for(int i=0; i<n; i++)
	{
		cin >> x >> y;
		poses[i] = make_pair(x, y);
	}
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i != j)
			{
				auto pos1 = poses[i], pos2 = poses[j];
				adj[i].push_back(make_pair(dist(pos1.first-pos2.first, pos1.second-pos2.second), j));
			}
	
	cout << prim() << '\n';
	return 0;
}