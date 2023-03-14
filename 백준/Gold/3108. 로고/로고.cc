#include <iostream>
#include <algorithm>

#define MAX_N 1002

using namespace std;

struct Pos{
    // x1~x2
    // y1~y2
    int x1;
    int y1;
    int x2;
    int y2;
}typedef pos;

int n;
int cnt;
pos square[MAX_N];
int parent[MAX_N];

int find_parent(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;
    parent[py] = px;
    cnt--;
}

inline bool isJoint(int i, int j)
{
    if(square[i].x1 > square[j].x1)
    {
        int temp = i;
        i = j;
        j = temp;
    }

    pos& a = square[i]; // (a.x1, a.y1) ~ (a.x2 ~ a.y2)
    pos& b = square[j]; // (b.x1, b.y1) ~ (b.x2 ~ b.y2)

    if(b.x1 > a.x2 || b.y1 > a.y2 || b.x2 < a.x1 || b.y2 < a.y1) return false;
    if(a.x1 < b.x1 && a.y1 < b.y1 && b.x2 < a.x2 && b.y2 < a.y2) return false;
    return true;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    cnt = n+1;
    for(int i=0; i<n; i++)
    {
        pos& p = square[i];
        cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;
        parent[i] = i;
    }
    square[n].x1 = square[n].y1 = 0;
    square[n].x2 = square[n].y2 = 0;
    parent[n] = n;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(isJoint(i, j))
            {
                merge(i, j);
            }
        }
    }
    cout << cnt-1 << '\n';

    return 0;
}