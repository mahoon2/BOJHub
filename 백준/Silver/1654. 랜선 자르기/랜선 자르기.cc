#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int n;
ll ans = 0;
vector<ll> lansun;

int slice_lan(ll length)
{
    int cnt = 0;
    for(auto& i: lansun)
        cnt += i / length;
    return cnt;
}

void binary_search(ll start, ll end)
{
    if(start > end) return;
    ll mid = (start + end) / 2;
    int cnt = slice_lan(mid);
    
//    cout << mid << " " << cnt << '\n';
    
    if(cnt == n) ans = max(ans, mid);
    if(cnt >= n) {ans = max(ans, mid); binary_search(mid+1, end);}
    else if(cnt < n) binary_search(start, mid-1);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int k;
    cin >> k >> n;
    
    ll max_lansun = 0;
    lansun = vector<ll>(k);
    for(int i=0; i<k; i++)
    {
        cin >> lansun[i];
        if(max_lansun < lansun[i])
            max_lansun = lansun[i];
    }
    
    binary_search(1, max_lansun);
    cout << ans << '\n';
    
    return 0;
}
