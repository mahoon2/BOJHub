#include <iostream>

using namespace std;

int uf[500000];

int find(int index)
{
	if(uf[index] == index) return index;
	return uf[index] = find(uf[index]);
}

bool merge(int parent, int child)
{
	int a = find(parent);
	int b = find(child);
	
	if(a == b) return true;
	uf[b] = a;
	return false;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m, temp1, temp2;
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
		uf[i] = i;
	
	for(int i=1; i<m+1; i++)
	{
		cin >> temp1 >> temp2;
		if(merge(temp1, temp2))
		{
			cout << i << '\n';
			return 0;
		}
	}
	
	cout << 0 << '\n';
	return 0;
}