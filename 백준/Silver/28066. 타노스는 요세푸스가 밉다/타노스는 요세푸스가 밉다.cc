#include <iostream>
#include <deque>

using namespace std;

int n, k;
deque<int> dq;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i=1; i<=n; i++)
    {
        dq.push_back(i);
    }

    while(dq.size() > k)
    {
        dq.erase(dq.begin()+1, dq.begin()+k);

        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << dq.front() << '\n';

    return 0;
}