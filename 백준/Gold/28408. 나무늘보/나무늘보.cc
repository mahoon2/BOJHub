#include <iostream>
#define MAX_N 500001
#define MOD 998244353

using namespace std;

int n;
int inp_pre[MAX_N], convert_post[MAX_N];

long long solve(int pre_start, int post_start, int m)
{  
    if(m == 1) return 1;

    int root = inp_pre[pre_start];
    if(root != post_start+m-1) return -1;

    int lroot = inp_pre[pre_start+1];
    if(lroot < post_start || lroot >= post_start+m-1) return -1;

    // left subtree
    // pre: pre_start+1 ~ pre_start+lm
    // post: post_start ~ lroot

    // right subtree
    // pre: pre_start+lm+1 ~ pre_start+m-1
    // post: lroot+1 ~ post_start+m-2

    int lm = lroot - post_start + 1;
    int rm = m - 1 - lm;
    
    long long ltemp, rtemp;
    ltemp = solve(pre_start+1, post_start, lm);
    if(rm == 0)
    {
        return ltemp == -1? -1 : (2*ltemp) % MOD;
    }

    rtemp = solve(pre_start+lm+1, lroot+1, rm);
    if(ltemp == -1 || rtemp == -1) return -1;
    return (ltemp * rtemp) % MOD;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int temp;
    for(int i=1; i<=n; i++)
    {
        cin >> temp;
        inp_pre[i] = temp;
    }
    for(int i=1; i<=n; i++)
    {
        cin >> temp;
        convert_post[temp] = i;
    }
    
    for(int i=1; i<=n; i++)
    {
        inp_pre[i] = convert_post[inp_pre[i]];
    }

    long long ret = solve(1, 1, n);
    if(ret == -1) cout << "0\n";
    else cout << ret % MOD << '\n';

    return 0;
}