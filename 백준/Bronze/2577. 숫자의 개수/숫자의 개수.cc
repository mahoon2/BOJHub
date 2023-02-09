#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    int cnt[10] = {0};
    cin >> a >> b >> c;
    n = a*b*c;
    while(n>0)
    {
        cnt[n%10]++;
        n /= 10;
    }
    for(int i=0; i<10; i++)
        cout << cnt[i] << '\n';
    return 0;
}