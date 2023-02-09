#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int temp, namuji[42];
    memset(namuji, 0, sizeof(namuji));
    for(int i=0; i<10; i++)
    {
        cin >> temp;
        namuji[temp%42]++;
    }
    
    int cnt=0;
    for(int i=0; i<42; i++)
        if(namuji[i] != 0)
            cnt++;
    
    cout << cnt;
    return 0;
}