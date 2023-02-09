#include <iostream>
#include <cstring>

using namespace std;

int k;
int e_cnt;
long long inp[2100000];
long long dp[2100000];

long long solve(int here)
{
	if(here > e_cnt) return 0;
	long long &ret = dp[here];
	if(ret != -1) return ret;
	
	int l = here*2 + 1;
	int r = here*2 + 2;
	
	long long sl = solve(l);
	long long sr = solve(r);
	
	if(sl < sr)
		inp[l] += sr-sl;
	else
		inp[r] += sl-sr;
	
	return ret = inp[here] + max(sl, sr);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> k;
	
	memset(dp, -1, sizeof(dp));
	int e = 1;
	int rep = 0;
	e_cnt = 0;
	
	while(++rep <= k)
	{
		e *= 2;
		
		if(rep != k)
			for(int i=0; i<e; i++)
				cin >> inp[++e_cnt];
		else
			for(int i=0; i<e; i++)
			{
				cin >> inp[++e_cnt];
				dp[e_cnt] = inp[e_cnt];
			}
	}
	
	inp[0] = 0;
	
	solve(0);
	long long ret = 0;
	for(int i=1; i<=e_cnt; i++)
		ret += inp[i];
	cout << ret << '\n';
	return 0;
}