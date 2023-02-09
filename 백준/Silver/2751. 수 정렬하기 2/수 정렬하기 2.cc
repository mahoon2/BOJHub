#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> inp, temp;

void merge(vector<int>& vec, int left, int right)
{
	int mid = (left + right) / 2, cnt = left;
	int lpoint = left, rpoint = mid+1;
	
	while(lpoint <= mid && rpoint <= right)
		if(vec[lpoint] < vec[rpoint])
			temp[cnt++] = vec[lpoint++];
		else
			temp[cnt++] = vec[rpoint++];
	
	if(lpoint > mid)
		while(rpoint <= right) temp[cnt++] = vec[rpoint++];
	else
		while(lpoint <= mid) temp[cnt++] = vec[lpoint++];
	
	for(int i=left; i<=right; i++)
		inp[i] = temp[i];
}

void merge_sort(vector<int>& vec, int left, int right)
{
	if(left >= right) return;
	
	int mid = (left + right) / 2;
	merge_sort(vec, left, mid);
	merge_sort(vec, mid+1, right);
	merge(vec, left, right);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	inp = temp = vector<int> (n);
	
	for(int i=0; i<n; i++)
		cin >> inp[i];
	merge_sort(inp, 0, n-1);
	for(int i=0; i<n; i++)
		cout << inp[i] << '\n';
	return 0;
}