#include <bits/stdc++.h>

#define INF 987654321
#define fi first
#define se second
#define pii pair<int,int>
#define vi vector<int>

#define FOR(i, n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;

using namespace std;

int n;
vi inp;

bool solve(vi& a, int cnt)
{
    if(cnt == 0)
    {
        FOR(i, n)
        {
            if(a[i] != i+1) return false;
        }
        return true;
    }

    vi temp(n);

    if(cnt != 2)
    {
        temp = a;
        FOR(j, n-1)
        {
            int last = temp[n-1];
            for(int i=n-2; i>=0; i--)
            {
                temp[i+1] = temp[i];
            }
            temp[0] = last;

            if(solve(temp, cnt-1))
            {
                cout << j+1 << '\n';
                return true;
            }
        }
    }
    else
    {
        bool started = false;
        int s = -1, e = -1;
        for(int i=0; i<n; i++)
        {
            if((a[i]+1)%n != a[(i+1)%n]%n)
            {
                if(!started)
                {
                    started = true;
                    s = (i==0)? i:i+1;
                }
            }
            else if(started)
            {
                e = i-1;
            }
        }

        if(e == -1) e = n-1;

        FOR(k, n)
        {
            if(k < s || k > e)
            {
                temp[k] = a[k];
            }
            else
            {
                temp[k] = a[s+e-k];
            }
        }

        if(solve(temp, cnt-1))
        {
            cout << s+1 << " " << e+1 << '\n';
            return true;
        }
    }

    return false;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    inp = vi(n);
    for(auto& i: inp)
    {
        cin >> i;
    }

    solve(inp, 3);
    
    return 0;
}