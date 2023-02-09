#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int m, temp, bitmask=0;
	string oper;
	cin >> m;
	while(m--)
	{
		cin >> oper;
		if(oper == "all")
		{
			for(int i=0; i<20; i++)
				bitmask |= (1<<i);
		}
		else if(oper == "empty")
			bitmask = 0;
		else
		{
			cin >> temp;
			temp--;
			if(oper == "add")
				bitmask |= (1<<temp);
			else if(oper == "remove")
				bitmask &= ~(1<<temp);
			else if(oper == "check")
				if(bitmask & (1<<temp))
					cout << 1 << '\n';
				else
					cout << 0 << '\n';
			else if(oper == "toggle")
				if(bitmask & (1<<temp))
					bitmask &= ~(1<<temp);
				else
					bitmask |= (1<<temp);
		}
	}
}