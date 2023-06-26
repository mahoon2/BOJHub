#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int n;
vector<array<int, 3>> inp;

bool compare(array<int, 3>& a, array<int, 3>& b)
{
    // a보다 b가 나중에 온다면 true 반환

    int a_cost = a[1]*b[0]; // a를 나중에 했을 때의 비용
    int b_cost = b[1]*a[0]; // b를 나중에 했을 때의 비용

    if(a_cost == b_cost) return a[2] < b[2];
    else return a_cost > b_cost;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;

    inp = vector<array<int, 3>> (n);

    int cnt = 1;
    for(auto& p: inp)
    {
        cin >> p[0] >> p[1];
        p[2] = cnt++;
    }

    sort(inp.begin(), inp.end(), compare);

    for(auto& p: inp)
    {
        cout << p[2] << " ";
    }
    cout << '\n';

    return 0;
}