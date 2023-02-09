#include <iostream>
#include <vector>

using namespace std;

int n, deleted_node, leaf=0;
vector<int> child[51];

void dfs(int here)
{
	int cnt = 0;
	for(int there: child[here])
		if(there == deleted_node) continue;
		else
		{
			cnt++;
			dfs(there);
		}
	
	if(cnt == 0)
		leaf++;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	int temp, root;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		if(temp == -1) {root = i; continue;}
		child[temp].push_back(i);
	}
	
	cin >> deleted_node;
	if(deleted_node == root)
		cout << "0\n";
	else
	{
		dfs(root);
		cout << leaf << '\n';
	}
	
	return 0;
}