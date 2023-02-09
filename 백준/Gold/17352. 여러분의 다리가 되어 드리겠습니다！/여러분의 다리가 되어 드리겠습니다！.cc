#include <iostream>

using namespace std;

int n;
int parent[300002];

int find_parent(int index)
{
	if(parent[index] == index) return index;
	else return parent[index] = find_parent(parent[index]);
}

void merge(int a, int b)
{
	if(find_parent(a) == find_parent(b)) return;
	parent[find_parent(a)] = find_parent(b);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int from, to;
	cin >> n;
	for(int i=0; i<=n; i++)
		parent[i] = i;
	
	for(int i=0; i<n-2; i++)
	{
		cin >> from >> to;
		merge(from, to);
	}
	
	int ret1 = -1, ret2 = -1;
	for(int i=1; i<=n; i++)
	{
		if(find_parent(i) == i)
			if(ret1 == -1) ret1 = i;
			else ret2 = i;
	}
	
	cout << ret1 << " " << ret2 << '\n';
	return 0;
}