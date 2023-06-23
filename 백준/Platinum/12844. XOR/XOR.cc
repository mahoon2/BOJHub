#include <iostream>
#define MAX_N 500001

using namespace std;

struct _Node{
    int start;
    int end;
    int ret;
}typedef Node;

int n;
int inp[MAX_N];
int lazy[4*MAX_N];
Node tree[4*MAX_N];

void init(int idx, int l, int r)
{
    Node& here = tree[idx];
    here.start = l;
    here.end = r;
    lazy[idx] = 0; // XOR의 항등원

    if(l == r) here.ret = inp[l];
    else
    {
        int mid = (l+r)/2;
        init(2*idx+1, l, mid);
        init(2*idx+2, mid+1, r);
        here.ret = tree[2*idx+1].ret ^ tree[2*idx+2].ret;
    }
}

void lazy_update(int idx)
{
    if(lazy[idx] != 0)
    {
        Node& here = tree[idx];
        if((here.end - here.start + 1)%2 == 1) here.ret ^= lazy[idx];
        if(here.start != here.end)
        {
            lazy[2*idx+1] ^= lazy[idx];
            lazy[2*idx+2] ^= lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int idx, int& l, int& r, int& diff)
{
    Node& here = tree[idx];
    lazy_update(idx);

    if(l > here.end || r < here.start) return;
    if(l <= here.start && here.end <= r)
    {
        if((here.end - here.start + 1)%2 == 1) here.ret ^= diff;
        if(here.start != here.end)
        {
            lazy[2*idx+1] ^= diff;
            lazy[2*idx+2] ^= diff;
        }
        return;
    }

    update(2*idx+1, l, r, diff);
    update(2*idx+2, l, r, diff);
    here.ret = tree[2*idx+1].ret ^ tree[2*idx+2].ret;
}

int query(int idx, int& l, int& r)
{
    Node& here = tree[idx];
    lazy_update(idx);

    if(l > here.end || r < here.start) return 0;
    if(l <= here.start && here.end <= r) return here.ret;
    return query(2*idx+1, l, r) ^ query(2*idx+2, l, r);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
    }

    init(0, 0, n-1);
    int m, op, i, j, k;
    cin >> m;
    while(m--)
    {
        cin >> op >> i >> j;
        if(i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }

        if(op == 1)
        {
            cin >> k;
            update(0, i, j, k);
        }
        else
        {
            cout << query(0, i, j) << '\n';
        }
    }

    return 0;
}