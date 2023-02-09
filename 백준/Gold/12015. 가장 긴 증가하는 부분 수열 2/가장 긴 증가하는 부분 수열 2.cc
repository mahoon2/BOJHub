#include <iostream>
#include <vector>

using namespace std;

int n, min_index;
vector<int> lis(1);

void binary_search(int start, int end, int& key)
{
	if(start == end)
	{
		if(lis[start] >= key)
			min_index = min(min_index, start);
		return;
	}
	
	int mid = (start + end)/2;
	if(lis[mid] >= key)
	{
		min_index = min(min_index, mid);
		binary_search(start, mid, key);
	}
	else
		binary_search(mid+1, end, key);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> lis[0];
	
	int inp;
	for(int i=1; i<n; i++)
	{
		cin >> inp;
		if(lis.back() < inp)
			lis.push_back(inp);
		else
		{
			min_index = 987654321;
			binary_search(0, lis.size()-1, inp);
			lis[min_index] = inp;
		}
	}
	
	cout << lis.size() << '\n';
	return 0;
}