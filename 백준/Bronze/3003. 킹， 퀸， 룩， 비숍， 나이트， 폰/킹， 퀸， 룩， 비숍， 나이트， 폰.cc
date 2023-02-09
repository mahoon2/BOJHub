#include <iostream>
using namespace std;

int main()
{
	int temp, chess[6] = {1, 1, 2, 2, 2, 8};
	for(int i=0; i<6; i++)
	{
		cin >> temp;
		cout << chess[i]-temp << " ";
	}
	return 0;
}