#include <iostream>

using namespace std;

int g, p, isdocked[100002];

int find_max_index(int index)
{
    if(isdocked[index] != index)
        return isdocked[index] = find_max_index(isdocked[index]);
    else
        return index;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> g >> p;
    for(int i=1; i<=g; i++)
        isdocked[i] = i;
    
    int gi, index;
    for(int i=0; i<p; i++)
    {
        cin >> gi;
        index = find_max_index(gi);
        if(index == 0)
        {
            cout << i << '\n';
            return 0;
        }
        isdocked[index] = index-1;
    }

    cout << p << '\n';
    return 0;
}