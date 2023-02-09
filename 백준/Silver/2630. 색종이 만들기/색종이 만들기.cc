#include <iostream>

using namespace std;

int n, board[128][128];
int paper[2] = {0, 0};

void quad(int x1, int x2, int y1, int y2)
{
	int color = board[x1][y1];
	bool is_same_color = true;
	for(int i=x1; i<x2; i++)
		for(int j=y1; j<y2; j++)
			if(board[i][j] != color)
			{
				is_same_color = false;
				break;
			}
	if(is_same_color)
	{
		paper[color]++;
		return;
	}
	
	int x_mid = (x1+x2)/2, y_mid = (y1+y2)/2;
	quad(x1, x_mid, y1, y_mid);
	quad(x_mid, x2, y1, y_mid);
	quad(x1, x_mid, y_mid, y2);
	quad(x_mid, x2, y_mid, y2);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	int temp;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin >> temp;
			board[i][j] = temp;
		}
	
	quad(0, n, 0, n);
	cout << paper[0] << '\n' << paper[1] << '\n';
	return 0;
}