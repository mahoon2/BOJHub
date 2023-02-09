#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> inp;
vector<int> result;
vector<int> used;

void sol()
{
	if(result.size()==m)
	{
		for(int i=0; i<m; i++)
			cout << result[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i=0; i<n; i++)
		if(!used[i])
		{
			used[i] = 1;
			result.push_back(inp[i]);
			sol();
			result.pop_back();
			used[i] = 0;
		}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int temp;
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		inp.push_back(temp);
	}
	sort(inp.begin(), inp.end());
	
	used = vector<int>(n,0);
	sol();
	
	return 0;
}