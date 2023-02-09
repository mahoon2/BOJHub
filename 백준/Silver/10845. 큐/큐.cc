#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, x;
	string oper;
	
	cin >> n;
	while(n--)
	{
		cin >> oper;
		if(oper == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if(oper == "pop")
		{
			if(q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if(oper == "size")
		{
			cout << q.size() << '\n';
		}
		else if(oper == "empty")
		{
			cout << (q.empty()? 1:0) << '\n';
		}
		else if(oper == "front")
		{
			if(q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if(oper == "back")
		{
			if(q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
	}
	
	return 0;
}