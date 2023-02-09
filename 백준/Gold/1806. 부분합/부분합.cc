#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> arr, sum;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> s;
	arr = sum = vector<int> (n);
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
	sum[0] = arr[0];
	for(int i=1; i<n; i++)
		sum[i] = sum[i-1] + arr[i];
	
	if(sum[n-1] < s)
	{
		cout << 0 << '\n';
		return 0;
	}
	
	int left = 0, right = 0;
	while(sum[right] < s && right <= n-1) {right++;}
	
	int current_sum, minimum_len = right+1;
	while(left <= right && right <= n-1)
	{
		current_sum = sum[right] - sum[left];
		if(current_sum >= s)
		{
//			cout << left << " " << right << '\n';
			minimum_len = min(minimum_len, right - left);
			left++;
		}
		else
			right++;
	}
	cout << minimum_len << '\n';
	return 0;
}