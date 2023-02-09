#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n;
int parent[3001];
vector<tuple<int,int,int>> pos; // (x,y,r)

int find_parent(int index)
{
	if(parent[index] == index) return index;
	else return parent[index] = find_parent(parent[index]);
}

void reset()
{
	for(int i=0; i<n; i++)
		parent[i] = i;
	pos = vector<tuple<int,int,int>> (n);
}

bool isJoint(int a, int b)
{
	tuple<int,int,int>& x = pos[a];
	tuple<int,int,int>& y = pos[b];
	
	int dist = ((get<0>(x) - get<0>(y))*(get<0>(x) - get<0>(y)) + (get<1>(x) - get<1>(y))*(get<1>(x) - get<1>(y)));
	
	return (dist <= (get<2>(x) + get<2>(y))*(get<2>(x) + get<2>(y)));
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> n;
		reset();
		for(int i=0; i<n; i++)
		{
			cin >> a >> b >> c;
			pos[i] = make_tuple(a, b, c);
		}
		
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if(isJoint(i, j)) parent[find_parent(j)] = find_parent(i);
		
		int ret = 0;
		for(int i=0; i<n; i++)
			if(find_parent(i) == i)
				ret++;
		cout << ret << '\n';
	}
	return 0;
}