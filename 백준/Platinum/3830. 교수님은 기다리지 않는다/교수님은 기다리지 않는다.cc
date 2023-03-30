#include <iostream>
#include <vector>

#define MAX_N 100002
using namespace std;

int n;
vector<long long> dist;
int parent[MAX_N];

inline int find(int here)
{
    if(parent[here] == here) return here;

    int p = find(parent[here]);
    dist[here] += dist[parent[here]];
    return parent[here] = p;
}

inline void merge(int x, int y, long long w)
{
    // x가 부모, y가 자식이 된다.
    int px = find(x);
    int py = find(y);

    if(px == py) return;
    parent[py] = px;
    dist[py] = dist[x] - dist[y] + w;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    while(true)
    {
        int m;
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        dist = vector<long long>(n+1, 0);
        for(int i=1; i<=n; i++)
        {
            parent[i] = i;
        }

        char c;
        int a, b, w;
        for(int i=0; i<m; i++)
        {
            cin >> c;
            if(c == '!')
            {
                cin >> a >> b >> w;
                merge(a, b, w);
            }
            else if(c == '?')
            {
                cin >> a >> b;
                if(find(a) == find(b))
                    cout << dist[b] - dist[a] << '\n';
                else
                    cout << "UNKNOWN\n";
            }
        }
    }

    return 0;
}