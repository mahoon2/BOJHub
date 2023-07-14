#include <iostream>
#include <cstring>
#define MAX_N 1000002

using namespace std;
typedef long long ll;

int n, k;
int ps[MAX_N];
int cnt[100000];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;

    memset(cnt, 0, sizeof(cnt));

    int inp;
    for(int i=0; i<n; i++)
    {
        cin >> inp;
        if(i>=1)
        {
            ps[i] = (ps[i-1] + inp) % k;
        }
        else
        {
            ps[i] = inp % k;
        }

        cnt[ps[i]]++;
    }

    int ret = 0;

    for(int i=0; i<k; i++)
    {
        ret = max(ret, cnt[i]);
    }

    cout << ret << '\n';

    return 0;
}