#include <iostream>

using namespace std;

int n;
int inp[101];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> inp[i];
    }

    long long ret = 0;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            ret += static_cast<long long>(inp[i]*inp[j]);
        }
    }

    cout << ret << '\n';

    return 0;
}