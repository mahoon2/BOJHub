#include <algorithm>
#include <iostream>
#include <vector>

#define MAX_N 100001
#define pii pair<int, int>

using namespace std;

struct _Pos {
  int x;
  int y;
  int z;
} typedef Pos;

int n;
int parent[MAX_N];
Pos inp[MAX_N];
pair<int, int> x[MAX_N];
pair<int, int> y[MAX_N];
pair<int, int> z[MAX_N];
vector<pair<int, pii>> weighted;

int abs(int x) { return (x > 0 ? x : -x); }

int find(int idx) {
  if (parent[idx] == idx)
    return idx;
  else
    return parent[idx] = find(parent[idx]);
}

void merge(int i1, int i2) {
  int p1 = find(i1), p2 = find(i2);
  if (p1 == p2)
    return;
  parent[p1] = p2;
}

long long kruskal() {
  long long ret = 0;

  for (int from = 0; from < n - 1; from++) {
    int to = from + 1;
    weighted.push_back(make_pair(abs(x[from].first - x[to].first),
                                 make_pair(x[from].second, x[to].second)));
    weighted.push_back(make_pair(abs(y[from].first - y[to].first),
                                 make_pair(y[from].second, y[to].second)));
    weighted.push_back(make_pair(abs(z[from].first - z[to].first),
                                 make_pair(z[from].second, z[to].second)));
  }

  sort(weighted.begin(), weighted.end());

  for (auto &w : weighted) {
    int cost = w.first, from = w.second.first, to = w.second.second;
    if (find(from) == find(to))
      continue;
    merge(from, to);
    ret += (long long)cost;
  }
  return ret;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    cin >> inp[i].x >> inp[i].y >> inp[i].z;
    x[i] = make_pair(inp[i].x, i);
    y[i] = make_pair(inp[i].y, i);
    z[i] = make_pair(inp[i].z, i);
  }

  sort(x, x + n);
  sort(y, y + n);
  sort(z, z + n);

  cout << kruskal() << '\n';

  return 0;
}