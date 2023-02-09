#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

#define INF 987654321
#define MAX_V 60

using namespace std;

bool dist[MAX_V][MAX_V];

int ctoi(char c)
{
	return (int)(c-'A');
}

char itoc(int i)
{
	return (char)(i+'A');
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	cin.ignore();
	
	memset(dist, false, sizeof(dist));
	for (int i=0; i<n; i++)
	{
		string input;
		getline(cin, input);
		if (input[0] == input[input.length() - 1]) continue;
		if (dist[ctoi(input[0])][ctoi(input[input.length() - 1])]) continue;
		cnt++;
		dist[ctoi(input[0])][ctoi(input[input.length() - 1])] = true;
	}

	for (int k=0; k<MAX_V; k++)
	{
		for (int i=0; i<MAX_V; i++)
		{
			for (int j=0; j<MAX_V; j++)
			{
				if (dist[i][j] || i==j) continue;
				dist[i][j] = dist[i][k] && dist[k][j];
				if (dist[i][j])
					cnt++;
			}
		}
	}

	cout << cnt << '\n';
	for (int i=0; i<MAX_V; i++)
		for (int j=0; j<MAX_V; j++)
			if (dist[i][j])
				cout << (char)(i + 'A') << " => " << (char)(j + 'A')<<'\n';
	
	return 0;
}