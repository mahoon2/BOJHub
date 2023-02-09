#include <iostream>
#include <vector>

using namespace std;

bool isNotPrime[1000002] = {false, };

void eratos()
{
	isNotPrime[0] = isNotPrime[1] = true;
	for(int i=2; i<=1001; i++)
	{
		if(isNotPrime[i]) continue;
		for(int j=2*i; j<1000002; j+=i)
			isNotPrime[j] = true;
	}
}

long long pow(long long a, int b)
{
	long long ret = 1;
	while(b--)
		ret *= a;
	return ret;
}

int main()
{
	long long n;
	cin >> n;
	eratos();
	
	int i = 2;
	long long temp = n;
	vector<pair<long long, int>> primes;
	while(i < 1000002 && 1 < temp)
	{
		if(temp%i == 0)
		{
			temp /= i;
			if(!primes.empty() && primes.back().first == i)
				primes.back().second++;
			else
				primes.push_back(make_pair(i, 1));
		}
		else
		{
			i++;
			while(i < 1000002 && isNotPrime[i])
				i++;
		}
	}
	
	if(temp > 1) primes.push_back(make_pair(temp, 1));
	long long ret = 1;
	for(auto& p: primes)
	{
		//cout << "p: " << p.first << " " << p.second << '\n';
		ret *= (pow(p.first, p.second)-pow(p.first, p.second-1));
	}
	
	cout << ret << '\n';
	return 0;
}