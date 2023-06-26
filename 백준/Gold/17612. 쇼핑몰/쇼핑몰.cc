#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(array<int,3>& a, array<int,3>& b)
    {
        // true라면 b가 a보다 top으로 올라간다.
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    }
};

int n, k;
// 누적 시간, 계산대 번호, 회원번호 순
vector<array<int,3>> order;
priority_queue<array<int,3>, vector<array<int,3>>, cmp> pq;

bool sort_comp(array<int,3>& a, array<int,3>& b)
{
    // b가 더 뒤에 오는 조건에서 true다.
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i=0; i<k; i++)
    {
        pq.push({0, i, 0});
    }

    int a, b;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        auto t = pq.top();
        pq.pop();

        if(t[2] != 0)
        {
            order.push_back(t);
        }

        pq.push({t[0]+b, t[1], a});
    }

    for(int i=0; i<k; i++)
    {
        auto t = pq.top();
        pq.pop();

        if(t[2] != 0)
        {
            order.push_back(t);
        }
    }

    sort(order.begin(), order.end(), sort_comp);

    long long ret = 0;
    for(int i=0; i<n; i++)
    {
        ret += (long long)((long long)order[i][2] * (long long)(i+1));
    }
    cout << ret << '\n';

    return 0;
}