#include <iostream>

using namespace std;

int main()
{
    int k, n;
    int prime[30] = {2003, 2011, 2017, 2027, 2029,
                2039, 2053, 2063, 2069, 2081,
                2083, 2087, 2089, 2099, 2111,
                2113, 2129, 2131, 2137, 2141,
                2143, 2153, 2161, 2179, 2203,
                2207, 2213, 2221, 2237, 2239};
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> k >> n;

    for(int i=0; i<k; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << prime[i]*j << " ";
        }
        cout << '\n';
    }

    return 0;
}