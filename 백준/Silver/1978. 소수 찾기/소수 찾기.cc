#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, inp, max=0;
	bool not_prime[1001] = {};
	vector<int> vec;
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> inp;
		vec.push_back(inp);
		if(max < inp)
			max = inp;
	}
	
	not_prime[1] = true;
	
	/*for(int i=1; i<=max; i++)
		cout << not_prime[i];
	cout<<endl;*/
	
	for(int i=2; i<=max/2; i++)
	{
		int j=2;
		while(i*j <= max)
		{
			not_prime[i*j] = true;
			j++;
		}
	}
	
	/*for(int i=1; i<=max; i++)
		cout << not_prime[i];
	cout<<endl;*/
	
	int prime_num=0;
	for(int i=0; i<vec.size(); i++)
		if(!not_prime[vec[i]])
			prime_num++;
	
	cout << prime_num << endl;
	
	return 0;
}