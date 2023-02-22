#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX_ERATOS 3163 // root(9999999) = 3162.28
#define MAX_NUM 9999999

using namespace std;

bool isPrime[MAX_NUM+1];
bool counted[MAX_NUM+1];

void do_eratos()
{
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i<=MAX_NUM; i++)
    {
        isPrime[i] = true;
    }

    for(int i=2; i<=MAX_ERATOS; i++)
    {
        for(int j=2; j<=(int)(MAX_NUM/i); j++)
        {
            isPrime[i*j] = false;
        }
    }
}

int count_prime(string& a, int n)
{
    int ret = 0;
    int len = a.size();

    vector<int> comb(len, 0);
    for(int i=0; i<n; i++)
    {
        comb[len-i-1] = 1;
    }

    do{
        string temp = "";
        for(int i=0; i<a.size(); i++)
        {
            if(comb[i])
            {
                temp += a[i];
            }
        }

        do{
            //cout << temp << ' ';
            int key = stoi(temp);
            //cout << key << ' ';

            if(!counted[key])
            {
                //cout << "Counted";
                counted[key] = true;
                if(isPrime[key])
                {
                    ret++;
                }
            }
            //cout << '\n';
        }while(next_permutation(temp.begin(), temp.end()));
    }while(next_permutation(comb.begin(), comb.end()));

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    do_eratos();

    int c;
    cin >> c;
    while(c--)
    {
        string inp;
        cin >> inp;
        sort(inp.begin(), inp.end());
        
        memset(counted, false, sizeof(counted));
        int ret = 0;
        for(int i=1; i<=inp.size(); i++)
        {
            ret += count_prime(inp, i);
        }
        cout << ret << '\n';
    }

    return 0;
}