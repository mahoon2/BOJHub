#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cost;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int temp;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		cost.push_back(temp);
	}
	sort(cost.begin(), cost.end());
	
	int sum=0;
	for(int i=0; i<n; i++)
		sum += (n-i)*cost[i];
	cout << sum << '\n';
	return 0;
}