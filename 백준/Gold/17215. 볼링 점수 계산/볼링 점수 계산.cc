#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    string inp;
    cin >> inp;

    int score[23];
    int check[23]; // 0 for nothing, 1 for spare, 2 for strike
    int idx = 0;
    int frame = 0;
    int ignore = 0;
    bool previous = false;
    while(idx < inp.size())
    {
        check[idx] = 0;
        if(inp[idx] == 'S')
        {
            if(frame <= 10) check[idx] = 2;
            score[idx] = 10;
            frame++;
            previous = false;
        }
        else if(inp[idx] == 'P')
        {
            if(frame <= 10) check[idx] = 1;
            score[idx] = 10-score[idx-1];
            frame++;
            previous = false;
        }
        else if(inp[idx] == '-')
        {
            score[idx] = 0;
            frame += previous;
            previous = !previous;
        }
        else
        {
            score[idx] = inp[idx] - '0';
            frame += previous;
            previous = !previous;
        }

        if(frame == 10)
        {
            if(inp[idx] == 'S') ignore = 2;
            else if(inp[idx] == 'P') ignore = 1;
        }
        //cout << inp[idx] << " " << frame << '\n';
        idx++;
    }
    //cout << "ignore: " << ignore << '\n';

    int ret = 0;
    for(int i=0; i<idx-ignore; i++)
    {
        if(check[i] == 0) ret += score[i];
        else if(check[i] == 1) ret += score[i] + score[i+1];
        else ret += score[i] + score[i+1] + score[i+2];
        //cout << ret << '\n';
    }
   //cout << '\n';
    cout << ret << '\n';

    return 0;
}