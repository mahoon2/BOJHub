#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, MIN=987654321;
bool isbroken[10] = {false};

void sol2(int a, int b, int digit)
{
	MIN = min(MIN, (a>b) ? (a-b+digit):(b-a+digit));
}

void sol(vector<int>& candidate, int index, int digit, int ret)
{	
	if(digit == 0)
	{
		sol2(ret, n, index);
		return;
	}

	for(int i=0; i<candidate.size(); i++)
		sol(candidate, index+1, digit/10, ret+(digit*candidate[i]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, temp;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		cin >> temp;
		isbroken[temp] = true;
	}
	
	vector<int> candidate;
	for(int i=0; i<10; i++)
		if(!isbroken[i])
			candidate.push_back(i);
	
	if(m==10)
	{
		sol2(100,n,0);
		cout << MIN << endl;
	}
	else if(n==0)
		cout << candidate[0] + 1 << endl;
	else
    {
        for(int digit=100000; digit>0; digit/=10)
            sol(candidate, 0, digit, 0);
        sol2(100, n, 0);
        cout << MIN << endl;
    }
	return 0;
}