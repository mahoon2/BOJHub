#include <iostream>

#define MAX_N 1000002

typedef long long ll;
using namespace std;

struct _Node{
    int start;
    int end;
    ll ret;
}typedef Node;

int n;
ll inp[MAX_N], lazy[4*MAX_N];
Node tree[4*MAX_N];

ll init(int idx, int l, int r)
{
    Node& here = tree[idx];
    here.start = l;
    here.end = r;
    lazy[idx] = 0;

    if(l == r) return here.ret = inp[l];

    int mid = (l+r)/2;
    return here.ret = init(2*idx+1, l, mid) + init(2*idx+2, mid+1, r);
}

void lazy_update(int idx)
{
    Node& here = tree[idx];

    if(lazy[idx] != 0)
    {
        here.ret += (here.end - here.start + 1)*lazy[idx];
        // 자식이 있는 경우 lazy를 분배한다.
        if(here.start != here.end)
        {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int idx, int& l, int& r, ll& diff)
{
    Node& here = tree[idx];
    lazy_update(idx);

    // 현재 idx가 전혀 포함되지 않음
    if(l > here.end || r < here.start) return;
    // 현재 idx가 완전히 포함됨
    if(l <= here.start && here.end <= r)
    {
        here.ret += (here.end - here.start + 1)*diff;
        // 자식이 있는 경우 diff를 분배한다.
        if(here.start != here.end)
        {
            lazy[2*idx+1] += diff;
            lazy[2*idx+2] += diff;
        }
        return;
    }

    // 현재 idx가 일부는 포함되고 일부는 그렇지 않음
    update(2*idx+1, l, r, diff);
    update(2*idx+2, l, r, diff);
    here.ret = tree[2*idx+1].ret + tree[2*idx+2].ret;
}

ll query(int idx, int& l, int& r)
{
    Node& here = tree[idx];
    lazy_update(idx);

    // 현재 idx가 전혀 포함되지 않음
    if(l > here.end || r < here.start) return 0;
    // 현재 idx가 완전히 포함됨
    if(l <= here.start && here.end <= r) return here.ret;

    // 현재 idx가 일부는 포함되고 일부는 그렇지 않음
    ll lRet = query(2*idx+1, l, r);
    ll rRet = query(2*idx+2, l, r);
    return lRet + rRet;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int m, k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++)
    {
        cin >> inp[i];
    }

    init(0, 1, n);

    int op, l, r;
    ll diff;
    int rep = m+k;
    while(rep--)
    {
        cin >> op;

        if(op == 1)
        {
            cin >> l >> r >> diff;
            update(0, l, r, diff);
        }
        else
        {
            cin >> l >> r;
            cout << query(0, l, r) << '\n';
        }
    }

    return 0;
}