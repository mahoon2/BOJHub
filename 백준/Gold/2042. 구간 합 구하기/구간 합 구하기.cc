#include <iostream>

using namespace std;

struct _Node{
	int start;
	int end;
	long long sum;
}typedef Node;

int n;
long long inp[1000001];
Node tree[4000001];

long long make_segment_tree(int a, int b, int idx)
{
	Node& here = tree[idx];
	here.start = a; here.end = b;
	if(a == b)
	{
		here.sum = inp[a];
	}
	else
	{
		int mid = (a+b)/2;
		int left = 2*idx+1;
		int right = 2*idx+2;
		here.sum = make_segment_tree(a, mid, left) + make_segment_tree(mid+1, b, right);
	}
	
	return here.sum;
}

void change(int tree_idx, int& idx, long long s)
{
	Node& here = tree[tree_idx];
	if(idx < here.start || here.end < idx) return;
	here.sum += s;
	
	if(here.start == here.end)
		return;
	
	int left = 2*tree_idx+1; int right = 2*tree_idx+2;
	int mid = (here.start + here.end) / 2;
	
	if(idx <= mid)
		change(left, idx, s);
	else
		change(right, idx, s);
}

long long get_sum(int a, int b, int idx)
{
	Node& here = tree[idx];
	int mid = (here.start + here.end) / 2;
	
	if(a == here.start && b == here.end) return here.sum;
	if(a <= mid && b <= mid)
		return get_sum(a, b, 2*idx+1);
	else if(mid < a && mid < b)
		return get_sum(a, b, 2*idx+2);
	else
		return get_sum(a, mid, 2*idx+1) + get_sum(mid+1, b, 2*idx+2);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m, k;
	cin >> n >> m >> k;
	
	for(int i=0; i<n; i++)
		cin >> inp[i];
	
	make_segment_tree(0, n-1, 0);
	
	int rep = m+k;
	int a, b;
	long long c;
	while(rep--)
	{
		cin >> a >> b >> c;
		b--;
		if(a == 1)
		{
			change(0, b, c-inp[b]);
			inp[b] = c;
		}
		else if(a == 2)
		{
			c--;
			cout << get_sum(b, c, 0) << '\n';
		}
	}
	return 0;
}