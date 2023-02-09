#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> data;
	int k, temp, sum=0;
	
	cin >> k;
	for(int i=0; i<k; i++)
	{
		cin >> temp;
		if(temp == 0)
		{
			data.pop();
			continue;
		}
		data.push(temp);
	}
	
	while(!data.empty())
	{
		sum += data.top();
		data.pop();
	}
	
	cout << sum << "\n";
	return 0;
}