#include <iostream>

#define MAX_N 100002

typedef long long ll;
using namespace std;

struct _Node{
    int start;
    int end;
    ll lazy;
}typedef Node;

int n;
int inp[MAX_N];
Node tree[4*MAX_N];

void init(int idx, int l, int r)
{
    Node& here = tree[idx];
    here.start = l;
    here.end = r;
    here.lazy = 0;
    
    if(l == r) return;

    int mid = (l+r)/2;
    init(2*idx+1, l, mid);
    init(2*idx+2, mid+1, r);
}

void update(int idx, int& l, int& r, int& diff)
{
    Node& here = tree[idx];

    if(l > here.end || r < here.start) return;
    if(l <= here.start && here.end <= r)
    {
        here.lazy += (ll)diff;
        return;
    }

    update(2*idx+1, l, r, diff);
    update(2*idx+2, l, r, diff);
}

ll query(int idx, int& l)
{
    Node& here = tree[idx];

    if(here.start == here.end && here.start == l) return here.lazy + inp[l];
    int mid = (here.start + here.end)/2;

    if(l <= mid) return here.lazy + query(2*idx+1, l);
    else return here.lazy + query(2*idx+2, l);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> inp[i];
    }

    init(0, 1, n);

    int op, l, r, diff;
    cin >> m;
    while(m--)
    {
        cin >> op;

        if(op == 1)
        {
            cin >> l >> r >> diff;
            update(0, l, r, diff);
        }
        else
        {
            cin >> l;
            cout << query(0, l) << '\n';
        }
    }

    return 0;
}