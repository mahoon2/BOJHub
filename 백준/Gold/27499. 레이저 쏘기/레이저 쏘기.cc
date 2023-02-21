#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int,int>> ret;

int gcd(int a, int b)
{
    if(b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int n;
    while(b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}

pair<int,int> parse(int x, int y)
{
    int g = gcd(x, y);
    return make_pair((int)(x/g), (int)(y/g));
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    int x, y;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        ret.push_back(parse(x, y));

        for(int j=1; j<k; j++)
        {
            if(j%2 == 1)
            {
                ret.push_back(parse(((int)((j-1)/2)+1)*2*m-x, y));
            }
            else
            {
                ret.push_back(parse(((int)((j-1)/2)+1)*2*m+x, y));
            }
        }
    }

    sort(ret.begin(), ret.end());

    int max_cnt = 0;
    int cnt = 1;
    for(size_t i=1; i<ret.size(); i++)
    {
        //cout << ret[i].first << ' ' << ret[i].second << '\n';
        if(ret[i-1] != ret[i])
        {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    cout << max_cnt << '\n';

    return 0;
}