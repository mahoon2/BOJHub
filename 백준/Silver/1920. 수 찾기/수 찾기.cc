#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int temp=0;
vector<int> vec;

void isInside(const vector<int>& vec, int start, int end)
{
	int mid = (start + end) / 2;
	
	if(start == end)
	{
		if(vec[start] == temp)
		{
			cout << "1\n";
			return;
		}
		else
		{
			cout << "0\n";
			return;
		}
	}
	
	if(start > end)
	{
		cout << "0\n";
		return;
	}
	
	if(vec[mid] == temp)
	{
		cout << "1\n";
		return;
	}
	
	if(vec[mid] < temp)
		isInside(vec, mid+1, end);
	
	if(vec[mid] > temp)
		isInside(vec, start, mid-1);
}

int main()
{
	int n, m, inp;
	cin.tie(nullptr);
    
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> inp;
		vec.push_back(inp);
	}
	sort(vec.begin(), vec.end());
	
	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> temp;
		isInside(vec, 0, n-1);
	}

}