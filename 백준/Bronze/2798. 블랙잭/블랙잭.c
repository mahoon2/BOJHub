#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    int card[100];
    int min=0, sum=0;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &card[i]);
    
   for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(card[i] > card[j])
            {
                int swap = card[i];
                card[i] = card[j];
                card[j]= swap;
            }
        }

    for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
              sum = card[i] + card[j] + card[k];
              if(sum > m)
                  break;
              if(m-min > m-sum)
                  min = sum;
            }
        }

    printf("%d", min);
    return 0;
}