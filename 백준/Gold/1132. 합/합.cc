#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX_POS 14

using namespace std;

typedef long long ll;

struct number{
    char c;
    int pos[MAX_POS];

    number()
    {
        for(int i=0; i<MAX_POS; i++) pos[i] = 0;
    }

    ll get_sum(int num)
    {
        ll ret = 0;
        ll base = 1;
        for(int i=0; i<MAX_POS; i++)
        {
            ret += (ll)(pos[i]) * base * num;
            base *= (ll)10;
        }

        return ret;
    }
};

int n;
vector<string> inp;
number alphabet[10];

bool comp(number& a, number& b)
{
    for(int i=MAX_POS-1; i>=0; i--)
    {
        if(a.pos[i] < b.pos[i]) return true;
        else if(a.pos[i] > b.pos[i]) return false;
    }

    return true;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    inp = vector<string> (n);
    vector<bool> canBeZero (10, true);

    for(int i=0; i<10; i++)
    {
        alphabet[i].c = 'A'+i;
    }

    for(auto& i: inp)
    {
        cin >> i;
        canBeZero[i[0]-'A'] = false;

        for(int j=0; j<i.size(); j++)
        {
            alphabet[i[j]-'A'].pos[i.size()-j-1] += 1;
        }
    }

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<MAX_POS; j++)
        {
            if(alphabet[i].pos[j] >= 10)
            {
                alphabet[i].pos[j+1] += (int)(alphabet[i].pos[j]/10);
                alphabet[i].pos[j] %= 10; 
            }
        }
    }

    sort(alphabet, alphabet+10, comp);

    ll ret = 0;
    bool zeroCounted = false;
    int cnt = 1;
    for(int i=0; i<10; i++)
    {
        if(!zeroCounted && canBeZero[alphabet[i].c-'A'])
        {
            zeroCounted = true;
        }
        else
        {
            //cout << alphabet[i].c << " " << cnt << '\n';
            ret += alphabet[i].get_sum(cnt++);
        }
    }
    cout << ret << '\n';

    return 0;
}