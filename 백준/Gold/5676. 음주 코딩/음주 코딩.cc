#include <iostream>
#define MAX 100002

using namespace std;

struct _Node{
	int start;
	int end;
	int mul;
}typedef Node;

int n;
int inp[MAX];
Node tree[MAX*4];

int get(int x)
{
	if(x > 0) return 1;
	else if(x < 0) return -1;
	else return 0;
}

int make_tree(int start, int end, int idx)
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
		int mid = (start + end) / 2;
		here.mul = make_tree(start, mid, 2*idx+1) * make_tree(mid+1, end, 2*idx+2);
	}
	
	return here.mul;
}

int update(int& cIdx, int& cVal, int idx)
{
	Node& here = tree[idx];
	
	if(here.start == here.end)
		return here.mul = cVal;
	
	int mid = (here.start + here.end) / 2;
	if(cIdx <= mid)
		return here.mul = update(cIdx, cVal, 2*idx+1) * tree[2*idx+2].mul;
	else
		return here.mul = tree[2*idx+1].mul * update(cIdx, cVal, 2*idx+2);
}

int query(int start, int end, int idx)
{
	Node& here = tree[idx];
	
	if(here.start == start && here.end == end)
		return here.mul;
	
	int mid = (here.start + here.end) / 2;
	if(start <= mid && end <= mid)
		return query(start, end, 2*idx+1);
	else if(mid < start && mid < end)
		return query(start, end, 2*idx+2);
	else
		return query(start, mid, 2*idx+1) * query(mid+1, end, 2*idx+2);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int k;
	
	while(cin >> n >> k)
	{
		if(n == 0 && k == 0) break;
		
		int temp;
		for(int i=0; i<n; i++)
		{
			cin >> temp;
			inp[i] = get(temp);
		}
		
		make_tree(0, n-1, 0);
		
		char c;
		int a, b;
		while(k--)
		{
			cin >> c >> a >> b;
			if(c == 'C')
			{
				a--;
				int gb = get(b);
				if(inp[a] == gb) continue;
				
				update(a, gb, 0);
				inp[a] = gb;
			}
			else if(c == 'P')
			{
				a--; b--;
				int ret = query(a, b, 0);
				if(ret == -1) cout << "-";
				else if(ret == 1) cout << "+";
				else cout << "0";
			}
		}
		
		cout << '\n';
	}
	return 0;
}