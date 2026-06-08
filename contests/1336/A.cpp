#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;
using i64 = std::int64_t;
constexpr int root = 0;

struct node {
  int u, p;
};

void solve() {
  int n, k;
  std::cin >> n >> k;

  adjacency_list edges(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  std::vector<int> subtree_count(n);
  auto calculate_subtree_count = [&](this auto&& self, int u = root, int p = -1) -> int {
    int count = 0;
    for (int v : edges[u]) {
      if (v != p) {
        count += self(v, u);
      }
    }

    subtree_count[u] = count;
    return count + 1;
  };

  calculate_subtree_count();
  std::vector<int> levels(n);
  std::deque<node> queue({{root, -1}});
  int level = 0;
  while (!queue.empty()) {
    int m = queue.size();
    for (int i = 0; i < m; ++i) {
      auto [u, p] = queue.front();
      queue.pop_front();
      levels[u] = level;
      for (int v : edges[u]) {
        if (v != p) {
          queue.push_back({v, u});
        }
      }
    }

    ++level;
  }

  std::vector<int> scores(n);
  for (int u = 0; u < n; ++u) {
    scores[u] = levels[u] - subtree_count[u];
  }
  std::sort(scores.rbegin(), scores.rend());

  i64 total_happiness = 0;
  for (int i = 0; i < k; ++i) {
    total_happiness += scores[i];
  }

  std::cout << total_happiness << '\n';
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
