#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	int t;
	vector<string> ret;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	for(int i=0; i<t; i++)
	{
		int n;
		string cmd, inp, temp;
		deque<short> dq;
		
		cin >> cmd >> n >> inp;
		if(n!=0)
		{
			for(int i=1; i<inp.size(); i++)
			{
				if(inp[i]==',' || inp[i]==']')
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
				else
					temp.push_back(inp[i]);
			}
		}
		
		bool reversed=false;
		bool error=false;
		for(int j=0; j<cmd.size(); j++)
		{
			if(cmd[j] == 'R')
				reversed = !reversed;
			else
			{
				if(dq.size() == 0)
				{
					error = true;
					break;
				}
				if(reversed)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		
		if(error)
			ret.push_back("error");
		else
		{
			string temp = "[";
			if(dq.size() == 0)
				temp += "]";
			else if(reversed)
			{
				for(int j=dq.size()-1; j>0; j--)
					temp += to_string(dq[j]) + ",";
				temp += to_string(dq[0]) + "]";
			}
			else
			{
				for(int j=0; j<dq.size()-1; j++)
					temp += to_string(dq[j]) + ",";
				temp += to_string(dq[dq.size()-1]) + "]";
			}
			ret.push_back(temp);
		}
	}
	
	for(int i=0; i<ret.size(); i++)
		cout << ret[i] << endl;
	return 0;
}