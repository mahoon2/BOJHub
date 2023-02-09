#include <iostream>

int n;
bool isprime[4000001] = {false};
int partsum[300000] = {0};
using namespace std;

int main()
{
	scanf("%d", &n);
	for(int i=2; i<=n; i++)
		isprime[i] = true;
	for(int i=2; i<=n; i++)
	{
		if(!isprime[i])
			continue;
		for(int j=i*2; j<=n; j+=i)
			isprime[j] = false;
	}
	
	int cnt = 1;
	partsum[0] = 0;
	for(int i=2; i<=n; i++)
		if(isprime[i])
		{
			partsum[cnt] = partsum[cnt-1] + i;
			cnt++;
		}
	
	int left = 0, right = 1, ret = 0, here;
	while(right < cnt)
	{
		here = partsum[right] - partsum[left];
		if(here < n)
			right++;
		else if(here > n)
			left++;
		else
		{
			ret++;
			right++;
		}
	}
	cout << ret << '\n';
	return 0;
}