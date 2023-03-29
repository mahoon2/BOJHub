#include <iostream>

#define MAX_N 50001
#define MIN_REVERSE 987654321
#define MAX_REVERSE -1

using namespace std;

int n, start;
int min_node[4*MAX_N];
int max_node[4*MAX_N];

void update(int idx, int num)
{
    idx += start;

    while(idx >= 1)
    {
        min_node[idx] = min(min_node[idx], num);
        max_node[idx] = max(max_node[idx], num);
        idx /= 2;
    }
}

int query_max(int l, int r)
{
    l += start; r += start;

    int ret = MAX_REVERSE;
    while(l < r)
    {
        if(l & 1) ret = max(ret, max_node[l++]);
        l /= 2;
        if(r & 1 ^ 1) ret = max(ret, max_node[r--]);
        r /= 2;
    }

    if(l == r) ret = max(ret, max_node[l]);
    return ret;
}

int query_min(int l, int r)
{
    l += start; r += start;

    int ret = MIN_REVERSE;
    while(l < r)
    {
        if(l & 1) ret = min(ret, min_node[l++]);
        l /= 2;
        if(r & 1 ^ 1) ret = min(ret, min_node[r--]);
        r /= 2;
    }

    if(l == r) ret = min(ret, min_node[l]);
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;

    int i=1;
    while((1<<i) < n)
        i++;
    start = (1<<i)-1;

    for(int i=0; i<=4*n; i++)
    {
        min_node[i] = MIN_REVERSE;
        max_node[i] = MAX_REVERSE;
    }

    int a, b;
    for(i=1; i<=n; i++)
    {
        cin >> a;
        update(i, a);
    }

    while(q--)
    {
        cin >> a >> b;
        cout << query_max(a, b) - query_min(a, b) << '\n';
    }

    return 0;
}