#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	int n, temp;
	int data[10001] = {0,};
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &temp);
		data[temp]++;
	}
	
	for(int i=1; i<10001; i++)
	{
		if(data[i] == 0)
			continue;
		else
		{
			for(int j=0; j<data[i]; j++)
				printf("%d\n", i);
		}
	}
	return 0;
}