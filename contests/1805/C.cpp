#include <algorithm>
#include <iostream>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;

template <typename T> 
void setmax(T &x, const T &y) { if (y > x) x = y; }

void solve() {
  int n;
  std::cin >> n;

  adjacency_list edges(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  auto calculate_height = [&](this auto &&self, std::vector<int> &d, int u,
                              int p = -1, int h = 0) -> void {
    d[u] = h;
    for (int v : edges[u]) {
      if (v == p) continue;
      self(d, v, u, h + 1);
    }
  };

  std::vector<int> dx(n), dy(n);
  calculate_height(dx, 0);
  int x = std::ranges::max_element(dx) - dx.begin();
  calculate_height(dx, x);
  int y = std::ranges::max_element(dx) - dx.begin();
  calculate_height(dy, y);

  std::vector<int> d(n);
  for (int u = 0; u < n; ++u) {
    d[u] = std::max(dx[u], dy[u]);
  }
  std::ranges::sort(d);

  int i = 0;
  for (int k = 1; k <= n; ++k) {
    while (i < n && d[i] < k) {
      ++i;
    }

    int cuts = i;
    int connected_components = std::min(n, cuts + 1);
    std::cout << connected_components << " \n"[k == n];
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
