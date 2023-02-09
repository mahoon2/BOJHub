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

int make_segment_tree(int start, int end, int idx)
{
	Node& here = tree[idx];
	here.start = start;
	here.end = end;
	
	if(start == end)
		return here.minNum = inp[start];
	else
	{
		int mid = (start + end) / 2;
		return here.minNum = min(make_segment_tree(start, mid, 2*idx+1), make_segment_tree(mid+1, end, 2*idx+2));
	}
}

int change(int& cIdx, int idx)
{
	Node& here = tree[idx];
	int mid = (here.start + here.end) / 2;
	
	if(here.start == here.end)
	{
		if(here.start == cIdx) here.minNum = inp[cIdx];
		return here.minNum;
	}
	
	if(cIdx <= mid)
	{
		here.minNum = min(change(cIdx, 2*idx+1), tree[2*idx+2].minNum);
	}
	else
	{
		here.minNum = min(tree[2*idx+1].minNum, change(cIdx, 2*idx+2));
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
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> inp[i];
	
	make_segment_tree(0, n-1, 0);
	
	int m, a, b, c;
	cin >> m;
	while(m--)
	{
		cin >> a >> b >> c;
		if(a == 1)
		{
			b--;
			inp[b] = c;
			change(b, 0);
		}
		else
		{
			b--; c--;
			cout << query(b, c, 0) << '\n';
		}
	}
	return 0;
}