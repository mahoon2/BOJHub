#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cand;

void sol(int start, vector<int>& output)
{
	if(output.size()==m)
	{
		for(int i=0; i<m; i++)
			cout << output[i] << " ";
		cout << '\n';
		return;
	}
	
	for(int i=start; i<n; i++)
	{
		output.push_back(cand[i]);
		sol(i, output);
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
		cand.push_back(temp);
	}
	sort(cand.begin(), cand.end());
	vector<int> output;
	sol(0, output);
	return 0;
}