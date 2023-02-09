#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<pair<int,int>> points, temp;

bool isSorted(int i, int j)
{
	if(points[i].first == points[j].first)
		return (points[i].second < points[j].second);
	else
		return (points[i].first < points[j].first);
}

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int lpoint = left, rpoint = mid+1, cnt = left;
	
	while(lpoint <= mid && rpoint <= right)
		if(isSorted(lpoint, rpoint))
			temp[cnt++] = points[lpoint++];
		else
			temp[cnt++] = points[rpoint++];
	
	if(lpoint == mid+1)
		while(rpoint <= right) temp[cnt++] = points[rpoint++];
	else
		while(lpoint <= mid) temp[cnt++] = points[lpoint++];
	
	for(int i=left; i<=right; i++)
		points[i] = temp[i];
}

void merge_sort(int left, int right)
{
	if(left >= right) return;
	
	int mid = (left + right) / 2;
	merge_sort(left, mid);
	merge_sort(mid+1, right);
	merge(left, right);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	points = temp = vector<pair<int,int>>(n);
	
	int x, y;
	for(int i=0; i<n; i++)
	{
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}
	
	merge_sort(0, n-1);
	for(auto& point: points)
		cout << point.first << " " << point.second << '\n';
	return 0;
}