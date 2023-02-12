#include <iostream>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int n;
int inp[MAX_N];
int ans[MAX_N];
int cnt[4] = {0, };
int per[3] = {1, 2, 3};

int solve()
{
    int ret = 0;

    for(int first=0; first<cnt[per[0]]; first++) ans[first] = per[0];
    for(int second=cnt[per[0]]; second<cnt[per[0]]+cnt[per[1]]; second++) ans[second] = per[1];
    for(int third=cnt[per[0]]+cnt[per[1]]; third<n; third++) ans[third] = per[2];

    /*for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << '\n';*/

    int swap_needed[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    for(int i=0; i<n; i++)
    {
        if(inp[i] != ans[i])
        {
            int from = inp[i];
            int to = ans[i];
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

    ret += 2*swap_needed[1][2] + 2*swap_needed[1][3];

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
        cnt[inp[i]]++;
    }
    //cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << '\n' << '\n';

    int ret = 987654321;
    do{
        ret = min(ret, solve());
    }while(next_permutation(per, per+3));

    cout << ret << '\n';
    return 0;
}