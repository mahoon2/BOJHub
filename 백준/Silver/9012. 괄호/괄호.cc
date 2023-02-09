#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int cnt=0;
		string inp, out="YES";
		
		cin >> inp;
		for(int j=0; j<inp.size(); j++)
			if(inp[j] == '(')
				cnt++;
			else
			{
				if(cnt <= 0)
				{
					out = "NO";
					break;
				}
				cnt--;
			}
		
		if(cnt != 0)
			out = "NO";
		cout << out << endl;
	}
	
	return 0;
}