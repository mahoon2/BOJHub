#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, x, stack_size = 0;
	string oper;
	
	cin >> n;
	while(n--)
	{
		cin >> oper;
		if(oper == "push")
		{
			cin >> x;
			s.push(x);
			stack_size++;
		}
		else if(oper == "pop")
		{
			if(stack_size == 0)
			{
				cout << -1 << '\n';
				continue;
			}
			cout << s.top() << '\n';
			s.pop();
			stack_size--;
		}
		else if(oper == "size")
			cout << stack_size << '\n';
		else if(oper == "empty")
			cout << (stack_size==0? 1:0) << '\n';
		else if(oper == "top")
		{
			if(stack_size == 0)
			{
				cout << -1 <<'\n';
				continue;
			}
			cout << s.top() << '\n';
		}
	}
	return 0;
}