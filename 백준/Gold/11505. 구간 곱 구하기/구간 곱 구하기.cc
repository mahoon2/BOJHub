#include <iostream>

#define MAX 1000001
#define MOD 1000000007

typedef long long ll;

struct _Node{
	int mul;
	int start;
	int end;
}typedef Node;

using namespace std;

int n;
int inp[MAX];
Node tree[MAX*4];

int make_segment_tree(int start, int end, int idx)
{
	Node& here = tree[idx];
	here.start = start;
	here.end = end;
	if(start == end)
	{
		here.mul = inp[start];
	}
	else
	{
		int mid = (start + end)/2;
		int left = 2*idx+1;
		int right = 2*idx+2;
		ll mul = (ll)make_segment_tree(start, mid, left) * (ll)make_segment_tree(mid+1, end, right);
		here.mul = mul % MOD;
	}
	
//	cout << here.start << "~" << here.end << ": " << here.mul << '\n';
	return here.mul;
}

// 여기서 segfault
int get_mul(int start, int end, int idx)
{
	Node& here = tree[idx];
	if(here.start == start && here.end == end)
		return here.mul;
	else
	{
		int mid = (here.start + here.end) / 2;
		int left = 2*idx+1;
		int right = 2*idx+2;
		
		if(start <= mid && end <= mid)
			return get_mul(start, end, left);
		else if(mid < start && mid < end)
			return get_mul(start, end, right);
		else
		{
			ll ret = (ll)get_mul(start, mid, left)*(ll)get_mul(mid+1, end, right);
			return ret%MOD;
		}
	}
}

void change(int& cIdx, int& cNum, int idx)
{
	Node& here = tree[idx];
	if(here.start == here.end && here.start == cIdx)
	{
		here.mul = cNum;
		return;
	}
	
	int mid = (here.start + here.end) / 2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	if(cIdx <= mid)
		change(cIdx, cNum, left);
	else
		change(cIdx, cNum, right);
	
	int left_mul = tree[left].mul;
	int right_mul = tree[right].mul;
	ll ret = (ll)left_mul * (ll)right_mul;
	here.mul = ret%MOD;
	
//	cout << here.mul << '\n';
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
	while(rep--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1)
		{
			b--;
			change(b, c, 0);
		}
		else if(a == 2)
		{
			b--; c--;
			cout << get_mul(b, c, 0) << '\n';
		}
	}
	
	return 0;
}