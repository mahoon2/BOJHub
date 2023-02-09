#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int d(int n) { return (2*n)%10000; }
int s(int n) { return n==0? 9999:n-1; }
int l(int n)
{
	int a = n/1000, b = (n%1000)/100, c = (n%100)/10, d = n%10, temp=a;
	a=b, b=c, c=d, d=temp;
	return 1000*a+100*b+10*c+d;
}

int r(int n)
{
	int a = n/1000, b = (n%1000)/100, c = (n%100)/10, d = n%10, temp=d;
	d=c, c=b, b=a, a=temp;
	return 1000*a+100*b+10*c+d;
}

void bfs(int start, int end)
{
	bool solved = false;
	int prev[10000], temp[4];
	string oper_temp = "DSLR";
	vector<string> operation(10000);
	queue<int> q;
	
	memset(prev, -1, sizeof(prev));
	prev[start] = start;
	operation[start] = "start";
	q.push(start);
	
	while(!q.empty() && !solved)
	{
		int here = q.front();
		q.pop();
		temp[0] = d(here), temp[1] = s(here), temp[2] = l(here), temp[3] = r(here);
		for(int i=0; i<4; i++)
		{
			int there = temp[i];
			if(prev[there] == -1)
			{
				prev[there] = here;
				operation[there] = oper_temp[i];
				q.push(there);
			}
			if(there == end)
			{
				solved=true;
				break;
			}
		}
	}
	
	int go_prev = end;
	string oper = "";
	while(go_prev != start)
	{
		oper += operation[go_prev];
		go_prev = prev[go_prev];
	}
	reverse(oper.begin(), oper.end());
	cout << oper << '\n';
	
	return;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t, start, end;
	cin >> t;
	while(t--)
	{
		cin >> start >> end;
		bfs(start, end);
	}
	return 0;
}