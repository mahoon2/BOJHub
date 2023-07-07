#include <iostream>

using namespace std;

int n, m;

typedef struct Node{
    int parent;
    int cap;
    int rain;
    int size;
}Node;

Node tree[100001];
int flooded = 0;

int find_parent(int here)
{
    if(tree[here].parent == here) return here;
    else return tree[here].parent = find_parent(tree[here].parent);
}

inline bool isFlood(int idx)
{
    return tree[idx].cap < tree[idx].rain;
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;

    bool px_flood = isFlood(px);
    bool py_flood = isFlood(py);

    tree[px].parent = py;
    tree[py].cap += tree[px].cap;
    tree[py].rain += tree[px].rain;

    bool new_flood = isFlood(py);

    if(px_flood != new_flood) flooded += ((px_flood)? -tree[px].size : tree[px].size);
    if(py_flood != new_flood) flooded += ((py_flood)? -tree[py].size : tree[py].size);

    tree[py].size += tree[px].size;
    tree[px].cap = tree[px].rain = 0;
    tree[px].size = 0;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        tree[i].parent = i;
        tree[i].size = 1;
        cin >> tree[i].cap;
    }
    
    for(int i=0; i<n; i++)
    {
        cin >> tree[i].rain;
        if(tree[i].cap < tree[i].rain)
        {
            flooded++;
        }
    }

    int a, b, c;
    while(m--)
    {
        cin >> a;
        if(a == 2)
        {
            cout << flooded << '\n';
        }
        else
        {
            cin >> b >> c;
            b--; c--;
            merge(b, c);
        }
    }

    return 0;
}