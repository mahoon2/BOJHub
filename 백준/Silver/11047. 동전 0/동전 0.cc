#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, temp;
	vector<int> coin;
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		coin.push_back(temp);
	}
	
	int cnt = 0;
	for(int i=coin.size()-1; i>=0; i--)
	{
		if(coin[i] <= k)
		{
			temp = k / coin[i];
			cnt += temp;
			k -= temp * coin[i];
		}
	}
	cout << cnt << '\n';
	return 0;
}