#include <iostream>
#define MAX 100001

using namespace std;

struct _Node{
	int start;
	int end;
	int minNum;
}typedef Node;

int n;
int inp[MAX];
Node tree[MAX*4];

int make_tree(int start, int end, int idx)
{
	Node& here = tree[idx];
	here.start = start;
	here.end = end;
	
	if(start == end) 
		here.minNum = inp[start];
	else
	{
		int mid = (start + end) / 2;
		here.minNum = min(make_tree(start, mid, 2*idx+1),
						 make_tree(mid+1, end, 2*idx+2));
	}
	return here.minNum;
}

int query(int start, int end, int idx)
{
	Node& here = tree[idx];
	
	if(here.start == start && here.end == end) return here.minNum;
	
	int mid = (here.start + here.end) / 2;
	if(start <= mid && end <= mid) return query(start, end, 2*idx+1);
	else if(mid < start && mid < end) return query(start, end, 2*idx+2);
	else return min(query(start, mid, 2*idx+1), query(mid+1, end, 2*idx+2));
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
		cin >> inp[i];
	make_tree(0, n-1, 0);
	
	int a, b;
	while(m--)
	{
		cin >> a >> b;
		a--; b--;
		cout << query(a, b, 0) << '\n';
	}
	
	return 0;
}