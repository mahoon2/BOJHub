#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for(int i=0; i<n; i++)
    {
        int h, w, g;
        std::cin >> h >> w >> g;

        int div = (g-1)/h + 1;
        int res = g%h;
        if(res==0) res = h;
        std::cout<< res*100 + div << std::endl;
    }
}