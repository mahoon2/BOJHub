#include <iostream>

#define MAX_N 1000002

using namespace std;
typedef long long ll;

int n;
ll inp[MAX_N];
ll tree[MAX_N];

ll sum(int i)
{
    ll ret = 0;

    while(i >= 1)
    {
        ret += tree[i];
        i -= (i & -i);
    }

    return ret;
}

void update(int i, ll x)
{
    while(i <= n)
    {
        tree[i] += x;
        i += (i & -i);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m, k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++)
    {
        cin >> inp[i];
        update(i, inp[i]);
    }

    int q;
    ll a, b;
    for(int i=0; i<m+k; i++)
    {
        cin >> q >> a >> b;
        if(q == 1)
        {
            update(a, b-inp[a]);
            inp[a] = b;
        }
        else if(q == 2)
        {
            cout << sum(b) - sum(a-1) << '\n';
        }
    }

    return 0;
}