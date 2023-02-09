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
	
	int last_used=0;
	
	for(int i=0; i<inp.size(); i++)
		if(!used[i] && last_used != inp[i])
		{
			used[i] = 1;
			result.push_back(inp[i]);
			sol();
			result.pop_back();
			used[i] = 0;
			last_used = inp[i];
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
		/*bool exists = false;
		for(auto& j: inp)
			if(j==temp)
				exists = true;
		if(!exists)
			inp.push_back(temp);*/
		inp.push_back(temp);
	}
	sort(inp.begin(), inp.end());
	
	used = vector<int>(inp.size(),0);
	sol();
	
	return 0;
}