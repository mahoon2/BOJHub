#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> inp;

bool is_lexico_order(string& a, string& b)
{
	if(a.size() < b.size()) return true;
	if(a.size() > b.size()) return false;
	
	for(int i=0; i<a.size(); i++)
	{
		if(a[i] > b[i]) return false;
		if(a[i] < b[i]) return true;
	}
	return true;
}

void merge(vector<string>& vec, int left, int mid, int right)
{
	// left <= left_p <= mid, mid+1 <= right_p <= right 여야 함
	int left_p = left, right_p = mid+1, cnt=0;
	vector<string> temp(right-left+1);
	
	while(left_p <= mid && right_p <= right)
	{
		if(is_lexico_order(vec[left_p], vec[right_p]))
			temp[cnt++] = vec[left_p++];
		else
			temp[cnt++] = vec[right_p++];
	}
	
	if(right_p > right)
		while(left_p <= mid) temp[cnt++] = vec[left_p++];
	else
		while(right_p <= right) temp[cnt++] = vec[right_p++];
	
	for(int i=left; i<=right; i++)
		vec[i] = temp[i-left];
}

void merge_sort(vector<string>& vec, int left, int right)
{
	if(left >= right) return;
	
	int mid = (left + right) / 2;
	merge_sort(vec, left, mid);
	merge_sort(vec, mid+1, right);
	merge(vec, left, mid, right);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	inp = vector<string> (n);
	
	for(int i=0; i<n; i++)
		cin >> inp[i];

	merge_sort(inp, 0, inp.size()-1);
	cout << inp[0] << '\n';
	for(int i=1; i<n; i++)
	{
		if(inp[i-1] == inp[i])
			continue;
		cout << inp[i] << '\n';
	}
	return 0;
}