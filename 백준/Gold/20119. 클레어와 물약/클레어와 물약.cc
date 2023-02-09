#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 200002

using namespace std;

int n;
int ret = 0;
int from[MAX_N];
bool canMake[MAX_N];
vector<int> adj[MAX_N];
int methodToLiquid[MAX_N];
int indegree[MAX_N];
queue<int> q;

void bfs()
{
    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        for(auto& there: adj[here])
        {
            if(--indegree[there] == 0)
            {
                int& liquid = methodToLiquid[there];
                if(!canMake[liquid])
                {
                    q.push(methodToLiquid[there]);
                    canMake[liquid] = true;
                    ret++;
                }
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int m;
    cin >> n >> m;
    
    int k, to;
    memset(indegree, 0, sizeof(indegree));
    
    int methodCnt = 0;
    for(int i=0; i<m; i++)
    {
        cin >> k;

        for(int j=0; j<k; j++)
        {
            cin >> from[j];
        }

        cin >> to;
        methodToLiquid[methodCnt] = to;

        for(int j=0; j<k; j++)
        {
            adj[from[j]].push_back(methodCnt);
        }

        indegree[methodCnt++] = k;
    }

    memset(canMake, 0, sizeof(canMake));

    int l;
    cin >> l;
    for(int i=0; i<l; i++)
    {
        cin >> from[i];
        q.push(from[i]);
        canMake[from[i]] = true;
        ret++;
    }

    bfs();

    // 답 셀 때 ind == 0 인 것도 세고 애초에 내가 가지고 있던 것도 빠뜨리지 말기
    cout << ret << '\n';
    for(int i=1; i<=n; i++)
    {
        if(canMake[i])
            cout << i << " ";
    }
    cout << '\n';

    return 0;
}