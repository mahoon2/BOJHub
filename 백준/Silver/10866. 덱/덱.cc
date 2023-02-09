#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	string oper;
	int n, x;
	
	cin >> n;
	while(n--)
	{
		cin >> oper;
		if(oper == "push_front")
		{
			cin >> x;
			dq.push_front(x);
		}
		else if(oper == "push_back")
		{
			cin >> x;
			dq.push_back(x);
		}
		else if(oper == "pop_front")
		{
			cout << (dq.empty()? -1 : dq.front()) << '\n';
			if(!dq.empty()) dq.pop_front();
		}
		else if(oper == "pop_back")
		{
			cout << (dq.empty()? -1 : dq.back()) << '\n';
			if(!dq.empty()) dq.pop_back();
		}
		else if(oper == "size")
			cout << (dq.empty()? 0:dq.size()) << '\n';
		else if(oper == "empty")
			cout << (dq.empty()? 1:0) << '\n';
		else if(oper == "front")
			cout << (dq.empty()? -1:dq.front()) << '\n';
		else if(oper == "back")
			cout << (dq.empty()? -1:dq.back()) << '\n';
	}
	
	return 0;
}