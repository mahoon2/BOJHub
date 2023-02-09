#include <stdio.h>

int divSum(int m)
{
    int sum = m;
    for(int i=m; i>0; i/=10)
    {
        sum += i%10;
    }
    return sum;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<n+1; i++)
        if(divSum(i) == n)
        {
            printf("%d", i);
            return 0;
        }
    printf("0");
}