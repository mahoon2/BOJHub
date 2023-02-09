#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> inp;
vector<vector<int>> ispalin;

int sol(int start, int end)
{
	auto& ret = ispalin[start][end];
	if(ret != -1) return ret;
	if(start == end) return ret = 1;
	if(start+1 == end) return ret = (inp[start] == inp[end]? 1:0);
	if(inp[start] == inp[end]) return ret = sol(start+1, end-1);
	else return ret = 0;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	inp = vector<int> (n);
	for(int i=0; i<n; i++)
		cin >> inp[i];
	ispalin = vector<vector<int>> (n, vector<int>(n, -1));
	
	int m, start, end;
	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> start >> end;
		start--;
		end--;
		cout << sol(start, end) << '\n';
	}
}