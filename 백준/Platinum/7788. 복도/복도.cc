#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_K 1001

using namespace std;

int m, n, k;
int parent[MAX_K];
vector<pair<double,pair<int,int>>> sorted;
array<int,2> pillar[MAX_K];

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
}

inline double dist(int i, int j)
{
    auto [ix, iy] = pillar[i];
    auto [jx, jy] = pillar[j];

    return sqrt(((long long)(jx-ix))*(jx-ix) + ((long long)(jy-iy))*(jy-iy));
}

double mst()
{
    sort(sorted.begin(), sorted.end());

    for(auto i: sorted)
    {
        double d = i.first;
        int from = i.second.first; int to = i.second.second;
        merge(from, to);
        if(find_parent(k) == find_parent(k+1))
        {
            return d;
        }
    }
    
    return 0;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    cout << fixed;
    cout.precision(8);
    if(m == 0 || n == 0 || k == 0)
    {
        cout << 0.0 << '\n';
        return 0;
    }

    int x, y;
    for(int i=0; i<k; i++)
    {
        parent[i] = i;
        // y가 [0,n]임을 가정
        cin >> x >> y;
        pillar[i] = {y, x};
        sorted.push_back(make_pair(y, make_pair(i, k)));
        sorted.push_back(make_pair(n-y, make_pair(i, k+1)));
    }
    parent[k] = k; parent[k+1] = k+1;

    for(int i=0; i<k; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            sorted.push_back(make_pair(dist(i, j), make_pair(i, j)));
        }
    }

    double ret = mst()/2;
    if(ret > m) ret = m*1.0/2;
    cout << ret << '\n';

    return 0;
}