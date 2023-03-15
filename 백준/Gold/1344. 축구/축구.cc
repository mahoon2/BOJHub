#include <iostream>
#include <cmath>

using namespace std;

int a, b;
bool isPrime[19] = {false, false, true, true, false, true, false, true, false, false,
false, true, false, true, false, false, false, true, false};
int comb[19][19];

void calc_comb(int n)
{
    for(int i=1; i<=n; i++)
    {
        comb[i][0] = comb[i][i] = 1;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i-1; j++)
        {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a >> b;
    calc_comb(18);

    double retA = 0.0;
    double retB = 0.0;
    for(int i=0; i<=18; i++)
    {
        if(!isPrime[i])
        {
            retA += comb[18][i]*pow((double)a/100, i)*pow((double)(100-a)/100, 18-i);
            retB += comb[18][i]*pow((double)b/100, i)*pow((double)(100-b)/100, 18-i);
        }
    }

    cout << fixed;
    cout.precision(14);
    cout << 1-retA*retB << '\n';

    return 0;
}