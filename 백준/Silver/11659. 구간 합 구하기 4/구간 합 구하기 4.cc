#include <iostream>

using namespace std;

int n;
long long inp[100010];

int main()
{
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
  int m;
  cin >> n >> m;

  long long sum = 0;
  long long temp;
  for(int i=0; i<n; i++)
  {
    cin >> temp;
    sum += temp;
    inp[i] = sum;
  }

  int i, j;
  while(m--)
  {
    cin >> i >> j;
    i--; j--;
    if(i == 0) cout << inp[j] << '\n';
    else cout << inp[j] - inp[i-1] << '\n';
  }

  return 0;
}