#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<short> stair;
int arr[301][3];

int solution(int stair_num, int prev)
{
	if(arr[stair_num][prev] != 0)
		return arr[stair_num][prev];
	if(stair_num == 1 && prev == 2)
		return 0;
	
	if(prev==1)
		arr[stair_num][prev] = solution(stair_num-1, 2) + stair[stair_num];
	else
		arr[stair_num][prev] = max(solution(stair_num-2, 1), solution(stair_num-2, 2)) + stair[stair_num];
	
	return arr[stair_num][prev];
}

int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    stair.push_back(0);
	memset(arr, 0, sizeof(arr));
	
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        stair.push_back(temp);
    }
	arr[1][1] = stair[1];
	arr[2][1] = stair[1] + stair[2];
	arr[2][2] = stair[2];
    cout << max(solution(n, 1), solution(n, 2)) << endl;
}