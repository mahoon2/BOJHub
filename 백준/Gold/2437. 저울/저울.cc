#include <iostream>
#include <algorithm>

using namespace std;

int n;
int inp[1001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> inp[i];
    sort(inp, inp+n);

    int ret = 1;

    for(int i=0; i<n; i++)
    {
        if(ret < inp[i]) break;
        else ret += inp[i];
    }
    cout << ret << '\n';

    return 0;
}