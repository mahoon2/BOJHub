#include <iostream>
#include <cmath>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix matmul(matrix& a, matrix& b)
{
	matrix c(2, vector<ll>(2, 0));
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
		{
			for(int k=0; k<2; k++)
				c[i][j] += (a[i][k] * b[k][j]);
			c[i][j] %= MOD;
		}
	return c;
}

void matpower(matrix& mat, ll power)
{
	ll k = 0;
	matrix temp = {{1, 1}, {1, 0}};
	while(pow(2, k) <= power)
	{
		if(power & (ll(1)<<k))
			mat = matmul(mat, temp);
		k++;
		temp = matmul(temp, temp);
	}
}

int main()
{
	ll n;
	cin >> n;
	if(n==0) { cout << "0\n"; return 0; }
	if(n==1 || n==2) { cout << "1\n"; return 0; }
	
	matrix start = {{1, 0}, {0, 1}};
	matpower(start, n-1);
	cout << start[0][0] << '\n';
	return 0;
}