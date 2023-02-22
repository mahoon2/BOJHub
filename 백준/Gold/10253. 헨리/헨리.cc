#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
    // a > b임을 가정
    long long n;

    while(b != 0)
    {
        n = a%b;
        a = b;
        b = n;
    }

    return a;
}

long long solve(long long a, long long b)
{
    long long n;

    while(a != 1)
    {
        n = (long long)ceil((double)b/a);
        a = a*n-b;
        b *= n;

        long long x = gcd(b, a);
        a /= x;
        b /= x;
    }

    return b;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

    return 0;
}