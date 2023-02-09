#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder, idx;

void sol(int post_start, int post_end, int in_start, int in_end)
{
	if(post_start > post_end || in_start > in_end) return;
	
	int root = postorder[post_end];
	cout << root << " ";
	
	int left_size = idx[root] - in_start;
	sol(post_start, post_start+left_size-1, in_start, idx[root]-1);
	sol(post_start+left_size, post_end-1, idx[root]+1, in_end);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, temp;
	cin >> n;
	
	inorder = postorder = vector<int>(n);
	idx = vector<int>(n+1);
	
	for(int i=0; i<n; i++)
		cin >> inorder[i];
	for(int i=0; i<n; i++)
		cin >> postorder[i];
	for(int i=0; i<n; i++)
		idx[inorder[i]] = i;
	
	sol(0, n-1, 0, n-1);
	cout << '\n';
	return 0;
}