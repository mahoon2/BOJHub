#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int n;
long long w;
vector<array<long long,3>> sensor;
vector<pair<double,pair<int,int>>> sorted;
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
}

inline double dist(int a, int b)
{
    auto [ax, ay, ar] = sensor[a];
    auto [bx, by, br] = sensor[b];

    return sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) - (double)ar - (double)br;
}

double mst()
{
    sort(sorted.begin(), sorted.end());

    for(auto i: sorted)
    {
        double d = i.first;
        int from = i.second.first; int to = i.second.second;
        merge(from, to);
        if(find_parent(n) == find_parent(n+1))
        {
            return d;
        }
    }
    
    return 0;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    cout << fixed;
    cout.precision(6);

    while(t--)
    {
        cin >> w >> n;
        if(n == 0)
        {
            cout << w*1.0/2 << '\n';
            continue;
        }

        sensor = vector<array<long long,3>> (n);
        sorted.clear();
        for(int i=0; i<n+2; i++) parent[i] = i;

        long long x, y, r;
        for(int i=0; i<n; i++)
        {
            cin >> x >> y >> r;
            sensor[i] = {x, y, r};
            int left_dist = x-r;
            int right_dist = w-x-r;

            if(left_dist < 0) left_dist = 0;
            //왼쪽 벽
            sorted.push_back(make_pair((double)left_dist, make_pair(i,n)));

            if(right_dist < 0) right_dist = 0;
            //오른쪽 벽
            sorted.push_back(make_pair((double)right_dist, make_pair(i,n+1)));
        
        }

        double ret;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                ret = dist(i, j);
                //cout << ret << '\n';
                if(ret < 1e-8) ret = 0.0;
                sorted.push_back(make_pair(ret, make_pair(i,j)));
            }
        }

        cout << mst()/2 << '\n';
    }

    return 0;
}