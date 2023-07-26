#include <string>
#include <vector>

#define INF 987654321

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    vector<int> cnt(k+1, 0);
    for(auto i: score)
    {
        cnt[i]++;
    }
    
    int spare = 0;
    for(int i=k; i>=1; i--)
    {
        answer += int((cnt[i]+spare)/m)*m*i;
        spare = (spare + cnt[i]) % m;
    }
    
    return answer;
}