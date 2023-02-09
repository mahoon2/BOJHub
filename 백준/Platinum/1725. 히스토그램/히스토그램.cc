#include <iostream>
#include <stack>

using namespace std;

int n;
int inp[100002];

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> inp[i];
	inp[n] = -1;
	
	stack<pair<int,int>> st; // (idx, height) 의 쌍
	st.push(make_pair(-1,-1));
	
	int ret = 0;
	for(int i=0; i<n+1; i++)
	{
		while(st.size() > 1 && inp[st.top().first] > inp[i])
		{
			pair<int,int> last = st.top();
			st.pop();
			pair<int,int> prev = st.top();
			ret = max(ret, (i-prev.first-1)*last.second);
		}
		st.push(make_pair(i, inp[i]));
	}
	
	cout << ret << '\n';
	return 0;
}