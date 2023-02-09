#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
int ans[1001][1001];
int inp[1001][1001];
int change[3];

bool make_ans()
{
    int a = inp[0][0];
    int b = inp[1][0];
    int c = inp[1][1];

    if(a == b || b == c || c == a)
        return true;

    change[a] = a;
    change[b] = c;
    change[c] = b;

    int data[3];
    data[0] = a; data[1] = b; data[2] = c;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            ans[i][j] = data[(i+j)%3];
        }
    }

    return false;
}

ll solve(bool isChanged)
{
    ll ret = 0;
    int from, to;

    int swap_needed[3][3];

    for(int i=0; i<n; i++)
    {
        memset(swap_needed, 0, sizeof(swap_needed));

        for(int j=0; j<=i; j++)
        {
            if(isChanged) ans[i][j] = change[ans[i][j]];

            if(ans[i][j] != inp[i][j])
            {
                from = inp[i][j];
                to = ans[i][j];
                if(swap_needed[to][from])
                {
                    swap_needed[to][from]--;
                    ret++;
                }
                else
                {
                    swap_needed[from][to]++;
                }
            }
        }

        if(swap_needed[0][1] == swap_needed[1][2] && swap_needed[1][2] == swap_needed[2][0])
        {
            ret += (ll)(2*swap_needed[0][1]);
            swap_needed[0][1] = 0;
            swap_needed[1][2] = 0;
            swap_needed[2][0] = 0;
        }
        else
            return -1;
        
        if(swap_needed[0][2] == swap_needed[2][1] && swap_needed[2][1] == swap_needed[1][0])
        {
            ret += (ll)(2*swap_needed[0][2]);
            swap_needed[0][2] = 0;
            swap_needed[2][1] = 0;
            swap_needed[1][0] = 0;
        }
        else
            return -1;
        
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(swap_needed[i][j])
                    return -1;
    }

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> inp[0][0];

    if(n == 1)
    {
        cout << 0 << '\n';
    }
    else
    {
        cin >> inp[1][0];
        cin >> inp[1][1];

        if(make_ans())
        {
            cout << -1 << '\n';
            return 0;
        }

        int cnt[3];
        int ans_cnt[3];
        for(int i=2; i<n; i++)
        {
            for(int j=0; j<3; j++)
            {
                cnt[j] = 0;
                ans_cnt[j] = 0;
            }

            for(int j=0; j<=i; j++)
            {
                cin >> inp[i][j];
                cnt[inp[i][j]]++;
                ans_cnt[ans[i][j]]++;
            }

            for(int j=0; j<3; j++)
            {
                if(cnt[j] != ans_cnt[j])
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }

        ll ret1 = solve(false);
        ll ret2 = solve(true);
        
        if(ret1 == -1) cout << ret2 << '\n';
        else if(ret2 == -1) cout << ret1 << '\n';
        else cout << min(ret1, ret2) << '\n';
    }

    return 0;
}