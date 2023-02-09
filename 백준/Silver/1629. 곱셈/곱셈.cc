#include <iostream>
typedef long long ll;

using namespace std;

ll c;

ll sol(ll a, ll b)
{
	if(b == 0) return 1;
	else if(b == 1) return a;
	else if(b == 2) return (a*a)%c;
	
	if(b%2 == 0)
	{
		return sol((a*a)%c, ll(b/2)) % c;
	}
	else
	{
		return (sol((a*a)%c, ll(b/2)) * a) % c;
	}
}

int main()
{
	ll a, b;
	cin >> a >> b >> c;
	if(a > c) a = a%c;
	else if(a == c) { cout << "0\n"; return 0; }
	cout << sol(a, b) << '\n';
	return 0;
}