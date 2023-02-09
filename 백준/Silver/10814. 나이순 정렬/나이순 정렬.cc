#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int n;
vector<pair<int,string>> inp, temp;

void merge(int left, int right)
{
	int mid = (left + right) / 2, cnt = left;
	int lpoint = left, rpoint = mid+1;
	
	while(lpoint <= mid && rpoint <= right)
		if(inp[lpoint].first <= inp[rpoint].first)
			temp[cnt++] = inp[lpoint++];
		else
			temp[cnt++] = inp[rpoint++];
	
	if(lpoint > mid)
		while(rpoint <= right) temp[cnt++] = inp[rpoint++];
	else
		while(lpoint <= mid) temp[cnt++] = inp[lpoint++];
	
	for(int i=left; i<=right; i++)
		inp[i] = temp[i];
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
	inp = temp = vector<pair<int,string>> (n);
	
	int age;
	string name;
	
	for(int i=0; i<n; i++)
	{
		cin >> age >> name;
		inp[i].first = age;
		inp[i].second = name;
	}
	merge_sort(0, n-1);
	for(int i=0; i<n; i++)
		cout << inp[i].first << " " << inp[i].second << '\n';
	return 0;
}