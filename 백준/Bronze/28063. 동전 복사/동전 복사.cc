#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    int x, y;
    cin >> x >> y;

    if(n == 1) cout << "0\n";
    else
    {
        if((x == 1 || x == n) && (y == 1 || y == n)) cout << "2\n";
        else if((x == 1 || x == n) || (y == 1 || y == n)) cout << "3\n";
        else cout << "4\n";
    }

    return 0;
}