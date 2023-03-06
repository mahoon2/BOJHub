#include <iostream>
#include <cstring>
#include <vector>

#define MAX_N 101

using namespace std;

int n;
vector<int> heavy[MAX_N]; // h->l
vector<int> light[MAX_N]; // l->h
bool heavier[MAX_N];
bool lighter[MAX_N];

int heavy_dfs(int here)
{
    // 어떤 정점 u보다 무거운 정점의 수는
    // light 그래프를 따라 u에서 갈 수 있는 정점의 수와 같다.

    int ret = 1;
    heavier[here] = true;
    for(int& there: light[here])
    {
        if(!heavier[there])
        {
            ret += heavy_dfs(there);
        }
    }
    return ret;
}

int light_dfs(int here)
{
    int ret = 1;
    lighter[here] = true;
    for(int& there: heavy[here])
    {
        if(!lighter[there])
        {
            ret += light_dfs(there);
        }
    }
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    int h, l; // 무거운 h, 가벼운 l
    while(m--)
    {
        cin >> h >> l;
        if(h == l) continue;
        heavy[h].push_back(l);
        light[l].push_back(h);
    }

    int cnt = 0;
    int thresold = (n+1)/2;
    int ret;
    for(int i=1; i<=n; i++)
    {
        memset(heavier, false, sizeof(heavier));
        ret = heavy_dfs(i);
//        cout << i << " " << ret << " ";
        if(ret >= thresold+1) cnt++;
        else
        {
            memset(lighter, false, sizeof(lighter));
            ret = light_dfs(i);
//            cout << ret;
            if(ret >= thresold+1) cnt++;
        }
//       cout << '\n';
    }

    cout << cnt << '\n';

    return 0;
}