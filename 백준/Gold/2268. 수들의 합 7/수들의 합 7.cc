#include <iostream>
#include <cstring>
#define MAX 1000002

using namespace std;
typedef long long ll;

ll fenwick[MAX], inp[MAX];
int n;

void update(ll idx, ll val)
{
	while(idx <= n)
	{
		fenwick[idx] += val;
		idx += (idx & -idx);
	}
}

ll query(ll idx)
{
	ll ret = 0;
	while(0 < idx)
	{
		ret += fenwick[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	memset(inp, 0, sizeof(inp));
	memset(fenwick, 0, sizeof(fenwick));
	
	ll m, a, b, c;
	cin >> m;
	while(m--)
	{
		cin >> a >> b >> c;
		if(a == 0)
		{
			if(b > c) {ll temp=b; b=c; c=temp;}
			cout << query(c)-query(b-1) << '\n';
		}
		else
		{
			update(b, c-inp[b]);
			inp[b] = c;
		}
	}
	return 0;
}