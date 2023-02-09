#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n;
	cin >> m >> n;
	
	int *ptr = new int[n-m+1]();
	
	for(int i=2; i<=int(sqrt(n)); i++)
	{
		int j=2;
		while(i*j < m)
			j++;
		while(i*j <= n)
		{
			ptr[i*j-m] = 1;
			j++;
		}
	}
    
    if(m==1)
        ptr[0] = 1;
	
	for(int i=0; i<n-m+1; i++)
		if(ptr[i] != 1)
			cout << i+m << "\n";
	return 0;
}