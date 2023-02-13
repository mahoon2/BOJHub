#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100001
#define MOD 1000000000

using namespace std;

int n;
int parent[MAX_N];
int size_num[MAX_N];
long long cost_sum = 0;
priority_queue<pair<int,pair<int,int> > > pq;

int find_parent(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

long long merge(int x, int y)
{
    // x가 속한 컴포넌트와 y가 속한 컴포넌트의
    // 원소 개수의 곱을 반환
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return 0;

    parent[py] = px;
    long long ret = (long long)size_num[px] * size_num[py];
    size_num[px] += size_num[py];
    size_num[py] = 0;

    return ret;
}

long long solve()
{
    long long ret = 0;
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();

        ret = (ret + merge(from, to)*cost_sum) % MOD;
        cost_sum -= (long long)cost;
//        cout << '(' << from << ',' << to << ") " << cost << ": " << ret << '\n';
    }

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    int from, to, cost;
    for(int i=0; i<m; i++)
    {
        cin >> from >> to >> cost;
        pq.push(make_pair(cost,make_pair(from, to)));
        cost_sum += (long long)cost;
    }

    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        size_num[i] = 1;
    }

    cout << solve() << '\n';

    return 0;
}