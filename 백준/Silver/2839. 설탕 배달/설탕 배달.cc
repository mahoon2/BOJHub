#include <iostream>
using namespace std;

int main()
{
	int n, temp=0;
	cin >> n;
	
	while(true)
	{
		temp++;
		if(temp*5>n)
			break;
	}
	
	temp--;
	for(; temp>=0; temp--)
	{
		if((n-temp*5)%3 == 0)
		{
			cout << temp+(int)((n-temp*5)/3);
			break;
		}
	}
	
	if(temp == -1)
		cout << "-1";
	return 0;
}