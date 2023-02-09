#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr, dp;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int n, temp;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	
	int answer = 0;
	dp = vector<int>(n, 1);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<i; j++)
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j]+1);
		answer = max(answer, dp[i]);
	}
	
	cout << answer << '\n';
	return 0;
}