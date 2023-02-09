#include <iostream>
#include <vector>
#define ABS(x) (((x)>=0)? ((x)):(-(x)))

using namespace std;
int n, ret_i, ret_j, ret = 2000000000;
vector<int> water;

void bs(int index, int left, int right)
{	
	int mid = (left + right) / 2;
	if(ret > ABS(water[index] + water[mid]))
	{
		ret = ABS(water[index] + water[mid]);
		ret_i = (index < mid? index: mid);
		ret_j = (index > mid? index: mid);
	}
	
	if(left >= right) return;
	
	if(water[index] < 0)
		if(ABS(water[index]) < ABS(water[mid]))
			bs(index, left, mid);
		else
			bs(index, mid+1, right);
	else if(water[index] > 0)
		if(ABS(water[index]) > ABS(water[mid]))
			bs(index, left, mid);
		else
			bs(index, mid+1, right);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	water = vector<int> (n);
	
	int sign_change_index = -1;
	for(int i=0; i<n; i++)
	{
		cin >> water[i];
		if(sign_change_index == -1 && water[i] >= 0)
			sign_change_index = i;
	}
	
	if(sign_change_index == 0)
		cout << water[0] << " " << water[1] << '\n';
	else if(sign_change_index == -1)
		cout << water[n-2] << " " << water[n-1] << '\n';
	else if(n == 2)
	{
		// 경우의 수가 하나밖에 없는 경우
		cout << water[0] << " " << water[1] << '\n';
	}
	else
	{	
		if(sign_change_index >= 2 && ret > ABS(water[sign_change_index-2] + water[sign_change_index-1]))
		{
			ret = ABS(water[sign_change_index-2] + water[sign_change_index-1]);
			ret_i = sign_change_index-2;
			ret_j = sign_change_index-1;
		}
		if(sign_change_index <= n-2 && ret > ABS(water[sign_change_index] + water[sign_change_index+1]))
		{
			ret = ABS(water[sign_change_index] + water[sign_change_index+1]);
			ret_i = sign_change_index;
			ret_j = sign_change_index+1;
		}
		
		for(int i=0; i<sign_change_index; i++)
			bs(i, sign_change_index, n-1);
		for(int i=sign_change_index; i<n; i++)
			bs(i, 0, sign_change_index-1);
		cout << water[ret_i] << " " << water[ret_j] << '\n';
	}
	return 0;
}