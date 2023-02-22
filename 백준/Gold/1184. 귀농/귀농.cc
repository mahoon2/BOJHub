#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int ret = 0;
int board[51][51];
int partial_sum[51][51];

priority_queue<int> pq1;
priority_queue<int> pq2;

// [y1, x1] ~ [y2, x2] 닫힌 구간의 직사각형 넓이 구하기
inline int get_partial_sum(int y1, int y2, int x1, int x2)
{
    if(y1 != 0 && x1 != 0)
        return partial_sum[y2][x2] - partial_sum[y2][x1-1] - partial_sum[y1-1][x2] + partial_sum[y1-1][x1-1];
    else if(y1 != 0 && x1 == 0)
        return partial_sum[y2][x2] - partial_sum[y1-1][x2];
    else if(y1 == 0 && x1 != 0)
        return partial_sum[y2][x2] - partial_sum[y2][x1-1];
    else
        return partial_sum[y2][x2];
}

void get_left_up(int y, int x)
{
    for(int i=y; i>=0; i--)
    {
        for(int j=x; j>=0; j--)
        {
            pq1.push(get_partial_sum(i, y, j, x));
        }
    }
}

void get_right_down(int y, int x)
{
    for(int i=y; i<N; i++)
    {
        for(int j=x; j<N; j++)
        {
            pq2.push(get_partial_sum(y, i, x, j));
        }
    }
}

void get_right_up(int y, int x)
{
    for(int i=y; i>=0; i--)
    {
        for(int j=x; j<N; j++)
        {
            pq1.push(get_partial_sum(i, y, x, j));
        }
    }
}

void get_left_down(int y, int x)
{
    for(int i=y; i<N; i++)
    {
        for(int j=x; j>=0; j--)
        {
            pq2.push(get_partial_sum(y, i, j, x));
        }
    }
}

void count()
{
    while(!pq1.empty() && !pq2.empty())
    {
        if(pq1.top() > pq2.top()) pq1.pop();
        else if(pq1.top() < pq2.top()) pq2.pop();
        else
        {
            int t = pq1.top();
            int c1 = 0;
            int c2 = 0;
            while(!pq1.empty() && pq1.top() == t)
            {
                pq1.pop();
                c1++;
            }
            while(!pq2.empty() && pq2.top() == t)
            {
                pq2.pop();
                c2++;
            }

            ret += c1*c2;
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;

    int y, x;
    for(int i=0; i<N; i++)
    {
        int temp = 0;
        for(int j=0; j<N; j++)
        {
            // (i,j) 에 저장된 정사각형은 해당 점을 왼쪽 위 꼭짓점으로 하는 사각형이다.
            // 즉 (i,j) ~ (i+1, j+1) 을 나타내는 것으로 한다.
            cin >> board[i][j];
            temp += board[i][j];
            partial_sum[i][j] = temp;

            if(i >= 1)
            {
                partial_sum[i][j] += partial_sum[i-1][j];
            }
        }
    }

    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            // 첫 정사각형은 (0, 0)
            // 마지막 정사각형은 (N-1, N-1)

            // 왼쪽 위 & 오른쪽 아래 체크
            pq1 = priority_queue<int> ();
            pq2 = priority_queue<int> ();
            get_left_up(i-1, j-1);
            get_right_down(i, j);
            count();

            // 오른쪽 위 & 왼쪽 아래 체크
            pq1 = priority_queue<int> ();
            pq2 = priority_queue<int> ();
            get_right_up(i-1, j);
            get_left_down(i, j-1);
            count();
        }
    }
    
    cout << ret << '\n';

    return 0;
}