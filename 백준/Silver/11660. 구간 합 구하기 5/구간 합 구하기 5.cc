//테케 2의 3번째 입력에서 오류
#include <iostream>

using namespace std;

int n;
int partial_sum[1024][1024];

int main()
{
	int m;
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	int sum, temp;
	for(int i=0; i<n; i++)
	{
		sum = 0;
		for(int j=0; j<n; j++)
		{
			cin >> temp;
			sum += temp;
			partial_sum[i][j] = sum;
		}
	}
	
	int x1, y1, x2, y2;
	for(int i=0; i<m; i++)
	{
		int sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		for(int j=x1; j<=x2; j++)
			if(y1 == 0)
				sum += partial_sum[j][y2];
			else
				sum += partial_sum[j][y2] - partial_sum[j][y1-1];
		cout << sum << '\n';
	}
	return 0;
}