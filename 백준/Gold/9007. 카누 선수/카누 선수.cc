#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define INF 987654321

using namespace std;

int k, n;
int kss[2][1001];
vector<int> kss_vec[2];

int abs(int a)
{
    return (a >= 0 ? a : -a);
}

int binary_search(int key)
{
    int lo = 0; // kss_vec[1][lo] <= key
    int hi = n*n-1; // kss_vec[1][hi] > key

    vector<int>& vec = kss_vec[1];
    if(vec[lo] > key) return lo;
    if(vec[hi] <= key) return hi;

    while(hi - lo != 1)
    {
        int mid = (lo + hi) / 2;
        if(vec[mid] <= key)
            lo = mid;
        else
            hi = mid;
    }

    return lo;
}

int solve()
{
    int ret = INF;

    for(int i=0; i<n*n; i++)
    {
        int idx = binary_search(k - kss_vec[0][i]);

        if(abs(ret-k) >= abs(k-(kss_vec[0][i] + kss_vec[1][idx])))
        {
            ret = kss_vec[0][i] + kss_vec[1][idx];
        }

        if(idx+1 < n*n && abs(ret-k) > abs(k-(kss_vec[0][i] + kss_vec[1][idx+1])))
        {
            ret = kss_vec[0][i] + kss_vec[1][idx+1];
        }

//        cout << kss_vec[0][i] + kss_vec[1][idx] << " " << ret << '\n';
        if(ret == k) break;
    }

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

//    ifstream fin; fin.open("test.inp");

    int t;
    cin >> t;

    while(t--)
    {
        cin >> k >> n;
        
        for(int rep=0; rep<2; rep++)
        {
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cin >> kss[i][j];
                }
            }

            kss_vec[rep].clear();

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    kss_vec[rep].push_back(kss[0][i] + kss[1][j]);
                }
            }
        }

        sort(kss_vec[1].begin(), kss_vec[1].end());

        cout << solve() << '\n';
    }

    return 0;
}