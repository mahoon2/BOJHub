#include <bits/stdc++.h>

#define INF 987654321
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second

#define FOR(i, n) for(int i=0; i<n; i++)
#define all(v) (v).begin(), (v).end()

using namespace std;

int inp[1000001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    int n;
    cin >> n;

    FOR(i, n)
    {
        cin >> inp[i];
    }

    sort(inp, inp+n);

    ll ret = 0;
    if(n%2)
    {
        if(n == 3)
        {
            ret = max(inp[2] - inp[0], inp[1] + inp[2] - 2*(inp[0]));
        }
        else
        {
            int i = n;
            int cnt;
            while(i--)
            {
                cnt = n-i;
                if(cnt <= (n-3)/2)
                {
                    ret += 2*inp[i];
                }
                else if(cnt <= (n+1)/2)
                {
                    ret += inp[i];
                }
                else
                {
                    ret -= 2*inp[i];
                }
            }

            ll temp = 0;
            i = n;
            while(i--)
            {
                cnt = n-i;
                if(cnt <= (n-1)/2)
                {
                    temp += 2*inp[i];
                }
                else if(cnt <= (n+3)/2)
                {
                    temp -= inp[i];
                }
                else
                {
                    temp -= 2*inp[i];
                }
            }
            ret = max(ret, temp);
        }
    }
    else
    {
        int i = n;
        int cnt;
        while(i--)
        {
            cnt = n-i;
            if(cnt <= (n-2)/2)
            {
                ret += 2*inp[i];
            }
            else if(cnt == n/2)
            {
                ret += inp[i];
            }
            else if(cnt == n/2+1)
            {
                ret -= inp[i];
            }
            else
            {
                ret -= 2*inp[i];
            }
        }
    }
    cout << ret << '\n';
    
    return 0;
}