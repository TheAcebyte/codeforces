#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  int s, t;
  std::cin >> s >> t;
  --s; --t;

  int A = *std::ranges::max_element(a);
  adjacency_list divisors(n);
  adjacency_list multiples(A + 1);
  for (int u = 0; u < n; ++u) {
    int x = a[u];
    for (int d = 2; d * d <= x; ++d) {
      if (x % d > 0) continue;
      while (x % d == 0) {
        x /= d;
      }

      divisors[u].push_back(d);
      multiples[d].push_back(u);
    }

    if (x > 1) {
      divisors[u].push_back(x);
      multiples[x].push_back(u);
    }
  }

  std::deque<int> queue({s});
  std::vector<bool> seen(A + 1);
  std::vector<int> previous(n, -1);
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop_front();

    for (int d : divisors[u]) {
      if (seen[d]) continue;
      seen[d] = true;

      for (int v : multiples[d]) {
        if (v == s || previous[v] != -1) continue;
        previous[v] = u;
        queue.push_back(v);
      }
    }
  }

  if (s != t && previous[t] == -1) {
    std::cout << -1 << '\n';
    return;
  }

  std::deque<int> path;
  int u = t;
  while (u != s) {
    path.push_front(u + 1);
    u = previous[u];
  }

  path.push_front(s + 1);
  int m = path.size();

  std::cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    std::cout << path[i] << " \n"[i == m - 1];
  }
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
