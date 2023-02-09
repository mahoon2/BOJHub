#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> data, out;
	list<int>::iterator iter;
	int n, k, cnt=1;
	
	cin >> n >> k;	
	for(int i=0; i<n; i++)
		data.push_back(i+1);
	
	if(k==1)
	{
		iter = data.begin();
		cout << "<";
		for(int i=0; i<data.size()-1; i++)
		{
			cout << *iter << ", ";
			iter++;
		}
		cout << *iter << ">";
		return 0;
	}
	
	iter = data.begin();
	while(data.size() != 0)
	{
		cnt++;
		iter++;
		if(iter == data.end())
			iter = data.begin();
		
		if(cnt%k == 0)
		{
			cnt = 1;
			out.push_back(*iter);
			iter = data.erase(iter);
			if(iter == data.end())
				iter = data.begin();
		}
	}
	
	iter = out.begin();
	cout << "<";
	for(int i=0; i<out.size()-1; i++)
	{
		cout << *iter << ", ";
		iter++;
	}
	cout << *iter << ">";
	return 0;
}