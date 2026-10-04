#include <iostream>
#include <vector>

template<typename T>
void setmin(T& x, const T& y) { if (y < x) x = y; }

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for (int& u : p) {
    std::cin >> u;
    --u;
  }

  std::vector<int> owner(n, -1);
  int components = 0;
  for (int u = 0; u < n; ++u) {
    if (owner[u] != -1) continue;
    ++components;

    int v = u;
    do {
      owner[v] = u;
      v = p[v];
    } while (v != u);
  }

  int min_operations = n;
  for (int u = 0; u < n - 1; ++u) {
    int union_or_cut = owner[u] == owner[u + 1] ? 1 : -1;
    int operations = n - components - union_or_cut;
    setmin(min_operations, operations);
  }

  std::cout << min_operations << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
