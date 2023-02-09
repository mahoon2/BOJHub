#include <iostream>
#include <vector>

using namespace std;

int n, cnt=0;
vector<int> answer;
vector<bool> used;

void sol(int k)
{
	if(k==n) {cnt++; return;}
	
	for(int i=0; i<n; i++)
		if(!used[i])
		{
			bool is_i_ok = true;
			for(int j=0; j<k; j++)
				if(answer[j]-i == k-j || i-answer[j] == k-j)
				{
					is_i_ok = false;
					break;
				}
			if(is_i_ok)
			{
				answer.push_back(i);
				used[i] = true;
				sol(k+1);
				answer.pop_back();
				used[i] = false;
			}
		}
}

int main()
{
	cin >> n;
	used = vector<bool>(n,false);
	sol(0);
	cout << cnt << '\n';
	return 0;
}