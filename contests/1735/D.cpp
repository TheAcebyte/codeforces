#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> deck(n, std::vector<int>(k));
  for (auto& c : deck) {
    for (int& x : c) {
      std::cin >> x;
    }
  }

  i64 meta_sets = 0;
  for (int i = 0; i < n; ++i) {
    std::set<std::vector<int>> existing_cards;
    i64 sets = 0;
    for (int j = 0; j < n; ++j) {
      std::vector<int> c(k);
      for (int l = 0; l < k; ++l) {
        int x = deck[i][l];
        int y = deck[j][l];
        int z = x == y ? x : 1 ^ 2 ^ x ^ y;
        c[l] = z;
      }

      if (existing_cards.find(c) != existing_cards.end()) {
        ++sets;
      }

      existing_cards.insert(deck[j]);
    }

    meta_sets += sets * (sets - 1) / 2;
  }

  std::cout << meta_sets << '\n';
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
