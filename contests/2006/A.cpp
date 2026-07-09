#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using adjacency_list = std::vector<std::vector<int>>;

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

  std::string s;
  std::cin >> s;

  auto is_leaf = [&](int u) {
    assert(u >= 0 && u < n);
    return edges[u].size() == 1;
  };

  int non_leaves_wildcards = 0;
  int leaves_wildcards = 0;
  int leaves_zeros = 0;
  int leaves_ones = 0;
  for (int u = 1; u < n; ++u) {
    if (!is_leaf(u) && s[u] == '?') {
      ++non_leaves_wildcards;
    } else if (is_leaf(u) && s[u] == '?') {
      ++leaves_wildcards;
    } else if (is_leaf(u) && s[u] == '0') {
      ++leaves_zeros;
    } else if (is_leaf(u) && s[u] == '1') {
      ++leaves_ones;
    }
  }

  int score = 0;
  if (s[0] == '0') {
    score = leaves_ones + (leaves_wildcards + 1) / 2;
  } else if (s[0] == '1') {
    score = leaves_zeros + (leaves_wildcards + 1) / 2;
  } else if (leaves_zeros == leaves_ones) {
    score = leaves_zeros + (leaves_wildcards + non_leaves_wildcards % 2) / 2;
  } else {
    score = std::max(leaves_zeros, leaves_ones) + leaves_wildcards / 2;
  }

  std::cout << score << '\n';
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
