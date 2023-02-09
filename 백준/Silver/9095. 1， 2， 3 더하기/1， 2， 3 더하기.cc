#include <iostream>

using namespace std;

int cnt;

void sol(int n)
{
	if(n==0)
	{
		cnt++;
		return;
	}
	
	for(int i=min(3,n); i>0; i--)
		sol(n-i);
}

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cnt = 0;
		sol(n);
		cout << cnt << '\n';
	}
	return 0;
}