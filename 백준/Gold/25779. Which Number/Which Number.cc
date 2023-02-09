#include <iostream>
#include <vector>

#define MAX_DEPTH 9223372036854775805

typedef long long ll;
using namespace std;

ll n;
int k;
ll inp[15];
vector<ll> add;
vector<ll> sub;

void pick(int rep, int index, ll result, int& sign)
{
    if(rep == 0)
    {
        if(sign == 1)
            add.push_back(result);
        else
            sub.push_back(result);
        return;
    }

    for(int i=index; i<k-rep+1; i++)
    {
        pick(rep-1, i+1, result*inp[i], sign);
    }
}

ll count_skip(ll here)
{
    ll ret = 0;

    for(ll i: add)
        ret += static_cast<ll>(here/i);
    for(ll i: sub)
        ret -= static_cast<ll>(here/i);
    
    return ret;
}

int main(void)
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=0; i<k; i++)
    {
        cin >> inp[i];
    }

    int sign = 1;
    for(int i=1; i<=k; i++)
    {
        pick(i, 0, 1, sign);
        sign = -sign;
    }

    ll left = 1;
    ll right = MAX_DEPTH;
    while(right - left != 1)
    {
        ll mid = (left + right) / 2;
        ll temp = mid - count_skip(mid);

        if(temp >= n)
            right = mid;
        else if(temp < n)
            left = mid;
    }
    cout << right << '\n';

    return 0;
}