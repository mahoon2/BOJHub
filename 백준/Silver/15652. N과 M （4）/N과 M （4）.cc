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
	
	for(int i=start; i<n; i++)
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
	
	cin >> n >> m;
	for(int i=1; i<n+1; i++)
		cand.push_back(i);

	sol(0);
	return 0;
}