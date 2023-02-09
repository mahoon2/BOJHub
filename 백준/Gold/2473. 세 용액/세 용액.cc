#include <iostream>
#include <vector>
#include <algorithm>
#define ABS(x) (((x) > 0) ? ((x)) : (-(x)))

typedef long long ll;
using namespace std;

int n;
vector<ll> water;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	water = vector<ll> (n);
	
	for(int i=0; i<n; i++)
		cin >> water[i];
	sort(water.begin(), water.end());
	
	ll min_sum = 3000000001;
	int ret1, ret2, ret3;
	for(int i=0; i<n; i++)
	{
		int left = i+1, right = n-1;
		while(left < right)
		{
			ll sum = water[i] + water[left] + water[right];
			if(ABS(sum) < min_sum)
			{
				min_sum = ABS(sum);
				ret1 = water[i];
				ret2 = water[left];
				ret3 = water[right];
			}
			if(sum > 0)
				right--;
			else if(sum < 0)
				left++;
			else
			{
				cout << ret1 << " " << ret2 << " " << ret3 << '\n';
				return 0;
			}
		}
	}
	
	cout << ret1 << " " << ret2 << " " << ret3 << '\n';
	return 0;
}