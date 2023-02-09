#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, cnt=0;
vector<pair<int, int>> conf;

void greedy(int selected)
{
	cnt++;
	int start_time = conf[selected].second;
	int end_time = conf[selected].first;
	
	for(int i=selected+1; i<n; i++)
		if(end_time <= conf[i].second)
		{
			greedy(i);
			return;
		}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	int start, end;
	for(int i=0; i<n; i++)
	{
		cin >> start >> end;
		conf.push_back(make_pair(end, start));
	}
	sort(conf.begin(), conf.end());
	greedy(0);
	cout << cnt << '\n';
	return 0;
}