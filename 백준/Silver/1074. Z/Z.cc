#include <iostream>
using namespace std;

int n, r, c, cnt=0;

int pow(int a, int b)
{
	int sum = 1;
	for(int i=0; i<b; i++)
		sum *= a;
	return sum;
}

void sol(int y, int x, int size)
{
	if(size == 1)
		cout << cnt << '\n';
	
	int next_size = size/2;
	int num = size*size/4;
	if(y<=r && r<y+next_size && x<=c && c<x+next_size)
	{
		sol(y, x, next_size);
	}
	else if(y<=r && r<y+next_size && x+next_size<=c && c<x+2*next_size)
	{
		cnt += num;
		sol(y, x+next_size, next_size);
	}
	else if(y+next_size<=r && r<y+2*next_size && x<=c && c<x+next_size)
	{
		cnt += (2*num);
		sol(y+next_size, x, next_size);
	}
	else if(y+next_size<=r && r<y+2*next_size && x+next_size<=c && c<x+2*next_size)
	{
		cnt += (3*num);
		sol(y+next_size, x+next_size, next_size);
	}
}

int main()
{
	cin >> n >> r >> c;
	sol(0, 0, pow(2,n));
	return 0;
}