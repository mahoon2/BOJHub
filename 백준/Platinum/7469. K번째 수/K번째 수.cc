#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100002
#define all(v) v.begin(), v.end()
#define INF 1000000000

using namespace std;

typedef struct Node{
    int start;
    int end;
    vector<int> sorted;
}Node;

int n;
int inp[MAX_N];
Node tree[4*MAX_N];

void init(int idx, int left, int right)
{
    Node& here = tree[idx];
    here.start = left; here.end = right;
    here.sorted = vector<int> (right - left + 1);

    if(left == right)
    {
        here.sorted[0] = inp[left];
        return;
    }

    int mid = (left + right)/2;
    init(2*idx, left, mid);
    init(2*idx+1, mid+1, right);

    merge(all(tree[2*idx].sorted), all(tree[2*idx+1].sorted), here.sorted.begin());
}

int bs(int idx, int& left, int& right, int& k)
{
    // k보다 작은 값이 몇 개?
    Node& here = tree[idx];

    if(here.end < left || right < here.start) return 0;
    if(left <= here.start && here.end <= right)
        return lower_bound(all(here.sorted), k) - here.sorted.begin();
    
    return bs(2*idx, left, right, k) + bs(2*idx+1, left, right, k);
}

int query(int& left, int& right, int& k)
{
    //if(left == right) return inp[left];
    int lo = -INF, hi = INF; // bs(lo) = 0, bs(hi) = n
    // bs(lo) <= k-1 < bs(hi) 인 관계 성립
    int mid, ret;

    while(lo + 1 != hi)
    {
        mid = (lo + hi)/2;
        ret = bs(1, left, right, mid);
       // cout << mid << " " << ret << '\n';
        if(ret <= k-1) lo = mid;
        else hi = mid;
    }

    return lo;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;

    for(int i=1; i<=n; i++)
    {
        cin >> inp[i];
    }

    init(1, 1, n);

    int i, j, k;
    while(q--)
    {
        cin >> i >> j >> k;
        cout << query(i, j, k) << '\n';
    }

    return 0;
}