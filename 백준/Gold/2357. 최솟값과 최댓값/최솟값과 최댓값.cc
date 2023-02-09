#include <iostream>

using namespace std;

struct _Node{
	int s;
	int e;
	int min;
	int max;
}typedef Node;

int inp[100001];
Node tree[400100];

void make_segment_tree(int a, int b, int idx)
{
	Node& here = tree[idx];
	here.s = a;
	here.e = b;
	if(a == b)
	{
		here.min = here.max = inp[a];
		//cout << idx << ": " << a << "~" << b << " min:" << here.min << " max:" << here.max << '\n';
		return;
	}
	
	int mid = (a+b)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	make_segment_tree(a, mid, left);
	make_segment_tree(mid+1, b, right);
	here.min = min(tree[left].min, tree[right].min);
	here.max = max(tree[left].max, tree[right].max);
	//cout << idx << ": " << a << "~" << b << " min:" << here.min << " max:" << here.max << '\n';

	return;
}

pair<int,int> find(int a, int b, int idx)
{
	Node& here = tree[idx];
	int mid = (here.s+here.e)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	if(here.s == a && here.e == b) return make_pair(here.min, here.max);
	else if(a <= mid && b <= mid) return find(a, b, left);
	else if(mid < a && mid < b) return find(a, b, right);
	else
	{
		pair<int,int> lp = find(a, mid, left);
		pair<int,int> rp = find(mid+1, b, right);
		return make_pair(min(lp.first, rp.first), max(lp.second, rp.second));
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> inp[i];
	
	make_segment_tree(0, n-1, 0);
	
	int a, b;
	while(m--)
	{
		cin >> a >> b;
		a--; b--;
		pair<int,int> ret = find(a, b, 0);
		cout << ret.first << " " << ret.second << "\n";
	}
	return 0;
}