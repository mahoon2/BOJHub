#include <iostream>
using namespace std;

int main()
{
	int temp, sum=0;
	for(int i=0; i<4; i++)
	{
		cin >> temp;
		sum += temp;
	}
	cout << int(sum/60) << endl;
	cout << sum%60;
	return 0;
}