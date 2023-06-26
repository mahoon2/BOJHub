#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int n;
vector<array<int, 2>> inp;

bool compare(array<int, 2>& a, array<int, 2>& b)
{
    // a보다 b가 나중에 온다면 true 반환

    int a_cost = a[1]*b[0]; // a를 먼저 했을 때의 비용
    int b_cost = b[1]*a[0]; // b를 먼저 했을 때의 비용

    return a_cost < b_cost;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    int a, b;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        if(b != 0)
        {
            inp.push_back({a, b});
        }
    }

    sort(inp.begin(), inp.end(), compare);

    long long ret = 0;
    for(auto& p: inp)
    {
        ret += p[0]*ret + p[1];
        ret %= 40000;
    }
    
    cout << ret << '\n';

    return 0;
}