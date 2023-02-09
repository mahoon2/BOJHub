#include <cstring>
#include <iostream>

using namespace std;

int n;
int rgb[1000][3];
int dp[1000][3][3];

int solve(int index, int last_choice, int& first_choice) {
  int &ret = dp[index][last_choice][first_choice];
  if (ret)
    return ret;
  if (index == n - 1) {
    ret = 1000001;
    for (int i = 0; i < 3; i++)
      if (i != last_choice && i != first_choice)
        ret = min(ret, rgb[index][i]);
    return ret;
  }

  if (last_choice == 0)
    ret = min(rgb[index][1] + solve(index + 1, 1, first_choice),
              rgb[index][2] + solve(index + 1, 2, first_choice));
  else if (last_choice == 1)
    ret = min(rgb[index][0] + solve(index + 1, 0, first_choice),
              rgb[index][2] + solve(index + 1, 2, first_choice));
  else if (last_choice == 2)
    ret = min(rgb[index][0] + solve(index + 1, 0, first_choice),
              rgb[index][1] + solve(index + 1, 1, first_choice));

  return ret;
}

int main() {
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < 3; i++) {
    dp[0][i][i] = rgb[0][i] + solve(1, i, i);
  }
  cout << min(dp[0][0][0], min(dp[0][1][1], dp[0][2][2])) << '\n';
}