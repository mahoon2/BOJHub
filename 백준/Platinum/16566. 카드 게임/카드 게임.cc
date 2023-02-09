#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> minsu;
vector<bool> isUsed;

int binary_search(int start, int end, int& key)
{
	int mid;
	
	while(start + 1 != end)
	{
		mid = (start + end) / 2;
		if(key < minsu[mid]) end = mid;
		else start = mid;
	}
	
	return end;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int k;
	cin >> n >> m >> k;
	
	int temp;
	for(int i=0; i<m; i++)
	{
		cin >> temp;
		minsu.push_back(temp);
		isUsed.push_back(false);
	}
	sort(minsu.begin(), minsu.end());
	
	while(k--)
	{
		cin >> temp;
		int candIdx = binary_search(-1, m, temp);
		for(int i=candIdx; i<m; i++)
			if(!isUsed[i])
			{
				isUsed[i] = true;
				cout << minsu[i] << '\n';
				break;
			}
	}
	return 0;
}