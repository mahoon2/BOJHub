#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	short board[100001][3];
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<3; j++)
			cin >> board[i][j];
	
	int max_ret, min_ret;
	int prev[3],  here[3] = {board[0][0], board[0][1], board[0][2]};
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<3; j++)
			prev[j] = here[j];
		here[0] = max(prev[0], prev[1]) + board[i][0];
		here[1] = max(max(prev[0], prev[1]), prev[2]) + board[i][1];
		here[2] = max(prev[1], prev[2]) + board[i][2];
	}
	max_ret = max(max(here[0], here[1]), here[2]);
	
	for(int i=0; i<3; i++)
		here[i] = board[0][i];
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<3; j++)
			prev[j] = here[j];
		here[0] = min(prev[0], prev[1]) + board[i][0];
		here[1] = min(min(prev[0], prev[1]), prev[2]) + board[i][1];
		here[2] = min(prev[1], prev[2]) + board[i][2];
	}
	min_ret = min(min(here[0], here[1]), here[2]);
	
	cout << max_ret << " " << min_ret << '\n';
	return 0;
}