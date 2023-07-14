#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<int> candy;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int ret = 0;
    candy = vector<int>(n);
    for(int i=0; i<n; i++)
    {
        cin >> candy[i];
        ret += candy[i];
    }

    sort(candy.begin(), candy.end());

    if(ret % 2 == 1)
    {
        for(auto& c: candy)
        {
            if(c % 2 == 1)
            {
                ret -= c;
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}