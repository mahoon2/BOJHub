#include <iostream>
#include <list>
using namespace std;

int main()
{
	bool isPrevOdd = false;
	int n, size;
	list<int> data;
	list<int>::iterator iter;
	
	cin >> n;
	if(n==1)
	{
		cout << "1";
		return 0;
	}
	
	for(int i=0; i<n; i++)
		data.push_back(i+1);
	/*for(const auto& num : data)
		cout << num << "\n";
	cout << "\n";*/

	size = n;
	iter = data.begin();
	if(size%2 == 1)
		isPrevOdd = !isPrevOdd;
	
	for(int i=0; i<(size+1)/2; i++)
	{
		iter = data.erase(iter);
		iter++;
	}
	/*for(const auto& num : data)
		cout << num << "\n";
	cout << "\n";*/
	
	size = data.size();
	
	while(size > 1)
	{
		//cout << "isPrevOdd : " << isPrevOdd << "\n";
		iter = data.begin();
		if(isPrevOdd)
			iter++;
		
		for(int i=0; i<(size+(!isPrevOdd))/2; i++)
		{
			iter = data.erase(iter);
			iter++;
		}
		
		if(size%2 == 1)
			isPrevOdd = !isPrevOdd;
		size = data.size();
		
		/*for(const auto& num : data)
			cout << num << "\n";
		cout << "\n";*/
	}
	
	/*for(const auto& num : data)
		cout << num << "\n";
	cout << "\n";*/
	cout << data.front() << "\n";
	return 0;
}