#include <iostream>

using namespace std;

struct _Node{
	int start;
	int end;
	int minIndex;
}typedef Node;

int n;
int inp[100001];
Node tree[400001];

int make_segment_tree(int start, int end, int idx)
{
	Node& here = tree[idx];
	here.start = start;
	here.end = end;
	
	if(start == end)
		here.minIndex = start;
	else
	{
		int mid = (start + end)/2;
		int left = 2*idx+1;
		int right = 2*idx+2;
	
		if(inp[make_segment_tree(start, mid, left)] <= inp[make_segment_tree(mid+1, end, right)])
			here.minIndex = tree[left].minIndex;
		else
			here.minIndex = tree[right].minIndex;
	}
	
	//cout << here.start << "~" << here.end << ": " << here.minIndex << '\n';
	return here.minIndex;
}

void change(int& cIdx, int idx)
{
	Node& here = tree[idx];
	if(here.start == here.end)
		return;
	
	int mid = (here.start + here.end)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	if(cIdx <= mid) change(cIdx, left);
	else change(cIdx, right);

	if(inp[tree[left].minIndex] <= inp[tree[right].minIndex])
		here.minIndex = tree[left].minIndex;
	else
		here.minIndex = tree[right].minIndex;
}

int get_min_index(int start, int end, int idx)
{
	Node& here = tree[idx];
	if(here.start == start && here.end == end)
		return here.minIndex;
	
	int mid = (here.start + here.end)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	if(start <= mid && end <= mid)
		return get_min_index(start, end, left);
	else if(mid < start && mid < end)
		return get_min_index(start, end, right);
	else 
	{
		int li = get_min_index(start, mid, left);
		int ri = get_min_index(mid+1, end, right);
		if(inp[li] <= inp[ri])
			return li;
		else
			return ri;
	}
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
		else if(a == 2)
		{
			b--; c--;
			cout << get_min_index(b, c, 0)+1 << '\n';
		}
	}
	
	return 0;
}