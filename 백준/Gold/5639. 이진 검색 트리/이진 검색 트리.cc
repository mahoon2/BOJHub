#include <iostream>
#include <vector>

using namespace std;

vector<int> inp;

void make_binary_tree(int left, int right)
{
	if(left == right) return;
	int root = left, cnt = left+1;
	while(cnt < right && inp[cnt] < inp[root])
		cnt++;
	
	make_binary_tree(left+1, cnt);
	make_binary_tree(cnt, right);
	cout << inp[root] << '\n';
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int temp;

	while(!cin.eof() && cin >> temp)
		inp.push_back(temp);
	make_binary_tree(0, inp.size());
	return 0;
}