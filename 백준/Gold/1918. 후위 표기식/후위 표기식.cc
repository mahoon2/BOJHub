#include <iostream>
#include <stack>
#include <string>

using namespace std;
string inorder;
stack<char> st;

int main()
{
	cin >> inorder;
	for(int i=0; i<inorder.size(); i++)
	{
		char c = inorder[i];
		if(c >= 'A' && c <= 'Z')
			cout << c;
		else
		{
			if(c == '(')
				st.push(c);
			else if(c == ')')
			{
				while(st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else if(c == '+' || c == '-')
			{
				while(!st.empty() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
			else if(c == '*' || c == '/')
			{
				while(!st.empty() && st.top() != '(' && st.top() != '+' && st.top() != '-')
				{
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
		}
	}
	
	while(!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	cout << '\n';
	
	return 0;
}