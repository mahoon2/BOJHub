#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int j;
	string temp;
	while(true)
	{
		bool pelindrom = true;
		cin >> temp;
		if(temp == "0") return 0;
		for(int i=0; i<temp.size()/2; i++)
		{
			j = temp.size()-i-1;
			if(temp[i] != temp[j])
			{
				pelindrom = false;
				break;
			}
		}
		
		if(pelindrom) cout << "yes\n";
		else cout << "no\n";
	}
}