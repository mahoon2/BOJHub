#include <iostream>
#include <string>
#define MOD 1234567891

using namespace std;

int main()
{
    int l, ret = 0, r = 1;
    char c;
    scanf("%d\n", &l);

    while(l--)
    {
        scanf("%c", &c);
        ret += ((c - 'a' + 1) * r) % MOD;
        r *= 31;
        ret %= MOD;
    }
    
    cout << ret << '\n';
    return 0;
}