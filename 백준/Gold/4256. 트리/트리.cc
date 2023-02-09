#include <iostream>
#include <stack>

#define MAX_N 1001

using namespace std;

int pre[MAX_N];
int in[MAX_N];
stack<int> ret;

void solve(int pre_left, int in_left, int num)
{
    // [left, left+num-1] 범위에 대해 풀이

    if(num <= 0) return;

    int& root = pre[pre_left];
    ret.push(root);

    int left_num = 0;
    while(in[in_left + left_num] != root)
    {
        left_num++;
    }

    int right_num = num - left_num - 1;

    // R subtree
    solve(pre_left+left_num+1, in_left+left_num+1, right_num);

    // L subtree
    solve(pre_left+1, in_left, left_num);

    // Root -> R -> L 순으로 Stack 에 쌓이므로
    // 이를 역순으로 꺼내면 postorder이 됨
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i=0; i<n; i++)
        {
            cin >> pre[i];
        }

        for(int i=0; i<n; i++)
        {
            cin >> in[i];
        }

        solve(0, 0, n);

        while(!ret.empty())
        {
            cout << ret.top() << " ";
            ret.pop();
        }

        cout << '\n';
    }

    return 0;
}