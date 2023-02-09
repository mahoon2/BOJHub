#include <iostream>

using namespace std;

long long inp[400001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    for(int i=0; i<n; i++)
        cin >> inp[i];
    
    int cmd, i, x, s;
    int current_shift = 0;

    while(q--)
    {
        cin >> cmd;
        if(cmd == 1)
        {
            cin >> i >> x;
            inp[(i-1+current_shift)%n] += x;
        }
        else if(cmd == 2)
        {
            cin >> s;
            current_shift = (current_shift + n - s) % n;
        }
        else if(cmd == 3)
        {
            cin >> s;
            current_shift = (current_shift + s) % n;
        }
    }

    int cnt = n;
    i = current_shift;
    while(cnt--)
    {
        cout << inp[i++] << " ";
        if(i == n) i = 0; 
    }
    cout << '\n';

    return 0;
}