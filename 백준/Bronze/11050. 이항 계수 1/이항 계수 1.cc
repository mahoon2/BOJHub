#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    if(k==n || k==0)
        std::cout << 1 << std::endl;
    else if(k==1)
        std::cout << n << std::endl;
    else
    {
        int div, mul=1;
        if(k > n/2)
            k = n - k;
        for(int i=0; i<k; i++)
            mul *= n--;
        
        if(k==2)
            div = 2;
        else if(k==3)
            div = 6;
        else if(k==4)
            div = 24;
        else if(k==5)
            div = 120;
        
        std::cout << mul/div << std::endl;
    }
}