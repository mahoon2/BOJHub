#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
multiset<int> dpq;

void print_depque()
{
	for(auto i=dpq.begin(); i!=dpq.end(); i++)
		cout << *i << " ";
	cout << '\n';
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int t, k;
	cin >> t;
	while(t--)
	{
		string oper;
		dpq.clear();
		cin >> k;
		while(k--)
		{
			cin >> oper >> n;
			if(oper[0] == 'D')
			{
				if(dpq.empty()) continue;
				if(n == 1) dpq.erase(--dpq.end());
				else if(n == -1) dpq.erase(dpq.begin());
			}
			else if(oper[0] == 'I')
			{
				dpq.insert(n);
				//print_depque();
			}
		}
		if(dpq.empty())
			cout << "EMPTY\n";
		else
			cout << *(--dpq.end()) << " " << *(dpq.begin()) << '\n';
	}
	return 0;
}