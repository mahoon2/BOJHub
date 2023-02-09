#include <iostream>
using namespace std;

int main()
{
	int l, p, inp[5];
	
	cin >> l >> p;
	for(int i=0; i<5; i++)
		cin >> inp[i];
	
	int temp=l*p;
	for(int i=0; i<5; i++)
		cout << inp[i]-temp << " ";
	return 0;
}