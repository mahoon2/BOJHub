#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, x, temp;
    cin >> n >> x;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        if(temp < x)
            cout << temp << " ";
    }
    return 0;
}