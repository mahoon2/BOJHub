#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int board[101][101];
deque<pair<int, int> > region;
int dp[11][(1<<11)];

/*int dy[] = {-1, -1, 1, 1};
int dx[] = {-1, 1, -1, 1};*/
int ret = 0;

pair<int,int> get_idx(pair<int,int>& x)
{
    int newY = ((x.first - x.second) + n) / 2;
    int newX = (x.first + x.second) / 2;

    return make_pair(newY, newX);
}

int get_dist(pair<int,int>& x, pair<int,int>& y)
{
    pair<int,int> nx = get_idx(x);
    pair<int,int> ny = get_idx(y);

    return abs(nx.first - ny.first) + abs(nx.second - ny.second);
}

int tsp(int idx, int visited)
{
    int& ret = dp[idx][visited];
    if(visited == ((1<<(region.size())) - 1))
    {
        return ret = 0;
    }

    if(ret != -1) return ret;

    ret = 987654321;
    for(int i=1; i<region.size(); i++)
    {
        if(visited & (1<<i)) continue;
        
        int dist = get_dist(region[idx], region[i]);
        ret = min(ret, tsp(i, visited | (1<<i)) + dist);
    }

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int modular = -1;
    pair<int,int> start;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 2)
            {
                modular = (i+j) % 2;
                start = make_pair(i, j);
                region.push_front(make_pair(i, j));
            }
            else if(board[i][j] == 1)
            {
                region.push_back(make_pair(i, j));
            }
        }
    }

    for(auto p: region)
    {
        if((p.first + p.second) % 2 != modular)
        {
            cout << "Shorei\n";
            return 0;
        }
    }

    cout << "Undertaker\n";
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n';

    return 0;
}