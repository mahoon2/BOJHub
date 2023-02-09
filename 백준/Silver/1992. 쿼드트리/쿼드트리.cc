#include <iostream>
#include <string>

using namespace std;

int n, inp[65][65];

void quad_tree(int y1, int y2, int x1, int x2)
{
	bool ok = true;
	int &first = inp[y1][x1];
	for(int i=y1; i<y2; i++)
		for(int j=x1; j<x2; j++)
			if(first != inp[i][j])
			{
				ok = false;
				break;
			}
	
	if(ok)
	{
		cout << first;
		return;
	}
	
	int mid = (y2-y1) / 2;
	cout << '(';
	quad_tree(y1, y1+mid, x1, x1+mid);
	quad_tree(y1, y1+mid, x1+mid, x2);
	quad_tree(y1+mid, y2, x1, x1+mid);
	quad_tree(y1+mid, y2, x1+mid, x2);
	cout << ')';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		cin >> s;
		for(int j=0; j<s.size(); j++)
		{
			if(s[j] == '1') inp[i][j] = 1;
			else inp[i][j] = 0;
		}
	}
	
	quad_tree(0, n, 0, n);
	cout << '\n';
	return 0;
}