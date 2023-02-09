#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int n, temp;
	cin >> n;
	priority_queue<int> pq;
	while(n--)
	{
		cin >> temp;
		if(temp)
			pq.push(temp);
		else
		{
			if(!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
	}
	return 0;
}