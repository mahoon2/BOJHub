#include <iostream>
#include <algorithm>
#define MAX_N 100002
#define all(v) v.begin(), v.end()

using namespace std;

typedef struct Node{
    int start;
    int end;
    vector<int> vec;
}Node;

int n;
int inp[MAX_N];
Node tree[4*MAX_N];

void init(int idx, int left, int right)
{
    Node& here = tree[idx];
    here.start = left;
    here.end = right;
    here.vec = vector<int> (right-left+1);

    if(left == right)
    {
        here.vec[0] = inp[left];
        return;
    }

    int mid = (left + right) / 2;
    init(2*idx+1, left, mid);
    init(2*idx+2, mid+1, right);

    vector<int>& lChild = tree[2*idx+1].vec;
    vector<int>& rChild = tree[2*idx+2].vec;
    merge(all(lChild), all(rChild), here.vec.begin());
}

int query(int idx, int& left, int& right, int& k)
{
    Node& here = tree[idx];

    if(left > here.end || here.start > right) return 0;
    if(left <= here.start && here.end <= right) return here.vec.end() - upper_bound(all(here.vec), k);

    return query(2*idx+1, left, right, k) + query(2*idx+2, left, right, k);
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

    int m, a, b, c;
    cin >> m;
    while(m--)
    {
        cin >> a >> b >> c;
        a--; b--;
        cout << query(0, a, b, c) << '\n';
    }

    return 0;
}