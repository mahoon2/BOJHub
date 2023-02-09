#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c;
	while(true)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0)
			return 0;
		if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
			printf("right\n");
		else
			printf("wrong\n");
	}
}