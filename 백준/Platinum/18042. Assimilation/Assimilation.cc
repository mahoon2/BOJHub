#include <iostream>
#include <set>

#define MAX_N 200001

typedef long long ll;
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int z;
    cin >> z;
    while(z--)
    {
        ll temp;
        ll max = 0;
        ll sum = 0;
        multiset<ll> s;

        int n;
        ll k;

        cin >> n >> k;
        for(int i=0; i<n; i++)
        {
            cin >> temp;
            sum += temp;
            if(temp > max)
                max = temp;

            s.insert(temp);
        }

        if(sum - max + k < max)
        {
            cout << -1 << '\n';
            continue;
        }

        int ret = 0;
        bool isOk = true;

        while(!s.empty() && k < sum)
        {
            auto iter = s.lower_bound(k);

            if(iter != s.end())
            {
                while(*iter > k && iter != s.begin())
                {
                    iter--;
                }
            }
            else
            {
                iter--;
            }

            if(iter == s.begin() && *iter > k)
            {
                cout << -1 << '\n';
                isOk = false;
                break;
            }

            ret++;
            sum -= *iter;
            k += *iter;
            s.erase(iter);
        }

        if(isOk)
            cout << ret << '\n';
    }

    return 0;
}