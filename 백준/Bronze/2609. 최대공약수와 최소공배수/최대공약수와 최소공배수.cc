#include <iostream>
using namespace std;

int main()
{
	int n, m, gcd;
	cin >> n >> m;
	
	int small = (n < m)? n : m;
	for(int i=1; i<=small; i++)
		if(n%i == 0 && m%i ==0)
			gcd = i;
	
	cout << gcd << "\n" << n*m/gcd << endl;
		
	return 0;
}