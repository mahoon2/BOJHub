#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cand;
vector<int> output;

void sol(int start)
{
	if(output.size()==m)
	{
		for(int i=0; i<m; i++)
			cout << output[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i=start; i<cand.size(); i++)
	{
		output.push_back(cand[i]);
		sol(i);
		output.pop_back();
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
		bool exists = false;
		for(auto& j: cand)
			if(j==temp)
				exists = true;
		if(!exists)
			cand.push_back(temp);
	}
	
	sort(cand.begin(), cand.end());
	sol(0);
	return 0;
}