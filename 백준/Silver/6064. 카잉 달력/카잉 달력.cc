#include <iostream>
using namespace std;

void swap(int &a, int &b)
{int temp=a; a=b; b=temp;}

int gcd(int a, int b)
{
	int ret = a%b==0? b:gcd(b, a%b);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, m, n, x, y;
	cin >> t;
	while(t)
	{
		t--;
		cin >> m >> n >> x >> y;
		if(x > y) {swap(m,n); swap(x,y);}
		
		int adder = y-x;
		int i_max = m/gcd(n, m);
		int ret = -1;
		for(int i=0; i<i_max; i++)
			if((n*i+adder)%m == 0)
				ret = n*i+y;
		
		cout << ret << '\n';
	}
	return 0;
}