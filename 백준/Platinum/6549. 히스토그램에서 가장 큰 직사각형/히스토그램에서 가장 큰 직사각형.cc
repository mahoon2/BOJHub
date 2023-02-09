#include <iostream>
#include <stack>

using namespace std;

int n;
long long inp[100002];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		
		for(int i=0; i<n; i++)
			cin >> inp[i];
		inp[n] = -1;

		stack<pair<long long, long long>> st; // (idx, height) 의 쌍
		st.push(make_pair(-1,-1));

		long long ret = 0;
		for(long long i=0; i<n+1; i++)
		{
			while(st.size() > 1 && inp[st.top().first] > inp[i])
			{
				pair<long long, long long> last = st.top();
				st.pop();
				pair<long long, long long> prev = st.top();
				ret = max(ret, (long long)((i-prev.first-1)*last.second));
			}
			st.push(make_pair(i, inp[i]));
		}

		cout << ret << '\n';
	}
	return 0;
}