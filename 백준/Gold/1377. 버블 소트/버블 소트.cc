#include <iostream>
#include <algorithm>

#define MAX_N 500001

using namespace std;

int n;
vector<pair<int,int>> inp;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int temp;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        inp.push_back(make_pair(temp, i));
    }

    sort(inp.begin(), inp.end());
    
    int ret = -1;
    for(int i=0; i<n; i++)
    {
        //cout << inp[i].second-i << '\n';
        ret = max(ret, inp[i].second-i);
    }
    cout << ret+1 << '\n';
    return 0;
}