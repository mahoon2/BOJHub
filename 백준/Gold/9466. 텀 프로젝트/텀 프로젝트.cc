#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int cnt, scc_cnt;
vector<int> adj, scc, discovered;
stack<int> st;

int dfs(int here)
{
	discovered[here] = cnt++;
	int ret = discovered[here];
	int there = adj[here];
	st.push(here);
	
	if(discovered[there] == -1)
		ret = min(ret, dfs(there));
	else if(scc[there] == -1)
		ret = min(ret, discovered[there]);
	
	if(ret == discovered[here])
	{
		while(1)
		{
			int t = st.top();
			st.pop();
			scc[t] = scc_cnt;
			if(t == here) break;
		}
		scc_cnt++;
	}
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n, temp;
		cin >> n;
		scc_cnt = cnt = 1;
		adj = vector<int>(n+1);
		scc = discovered = vector<int>(n+1, -1);
		
		for(int i=1; i<=n; i++)
			cin >> adj[i];
		
		for(int i=1; i<=n; i++)
			if(discovered[i] == -1)
				dfs(i);
		
		while(!st.empty())
			st.pop();
		
		int assa = 0;
		vector<int> is_scc_alone(n+1, 0);
		for(int i=1; i<=n; i++)
			is_scc_alone[scc[i]]++;
		for(int i=1; i<=n; i++)
			if(is_scc_alone[scc[i]] == 1 && adj[i] != i)
				assa++;
		cout << assa << '\n';
	}
	return 0;
}