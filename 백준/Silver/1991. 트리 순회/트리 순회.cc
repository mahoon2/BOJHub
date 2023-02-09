#include <iostream>
#include <vector>

using namespace std;

struct _Node{
	char name;
	int left;
	int right;
}typedef Node;

vector<Node> binary_tree;

void preorder(int here)
{
	cout << binary_tree[here].name;
	if(binary_tree[here].left != -1)
		preorder(binary_tree[here].left);
	if(binary_tree[here].right != -1)
		preorder(binary_tree[here].right);
}

void inorder(int here)
{
	if(binary_tree[here].left != -1)
		inorder(binary_tree[here].left);
	cout << binary_tree[here].name;
	if(binary_tree[here].right != -1)
		inorder(binary_tree[here].right);
}

void postorder(int here)
{
	if(binary_tree[here].left != -1)
		postorder(binary_tree[here].left);
	if(binary_tree[here].right != -1)
		postorder(binary_tree[here].right);
	cout << binary_tree[here].name;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	binary_tree = vector<Node>(n);
	for(int i=0; i<n; i++)
	{
		char name, left, right;
		cin >> name >> left >> right;
		binary_tree[name-'A'].name = name;
		if(left != '.')
			binary_tree[name-'A'].left = left-'A';
		else
			binary_tree[name-'A'].left = -1;
		if(right != '.')
			binary_tree[name-'A'].right = right-'A';
		else
			binary_tree[name-'A'].right = -1;
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}