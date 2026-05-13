#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k;
  std::string a, b;
  std::cin >> n >> k >> a >> b;

  std::set<char> q;
  std::vector<char> distincts;
  for (char c : a) {
    if (std::find(distincts.begin(), distincts.end(), c) == distincts.end()) {
      distincts.push_back(c);
    }
  }

  int d = distincts.size();
  k = std::min(d, k);

  auto has_character = [&](char c) { return q.find(c) != q.end(); };
  auto count_pairs = [&]() {
    int m = q.size();
    assert(m <= k);

    i64 pairs = 0;
    int i = 0;
    while (i < n) {
      if (a[i] != b[i] && !has_character(a[i])) {
        ++i;
        continue;
      }

      int j = i;
      while (j < n && (a[j] == b[j] || has_character(a[j]))) {
        pairs += j - i + 1;
        ++j;
      }

      i = j;
    }

    return pairs;
  };

  auto find_maximum_pairs = [&](this auto &&self,
                                int i = 0) -> i64 {
    int m = q.size();
    if (k - m > d - i) {
      return 0;
    }

    if (m == k) {
      return count_pairs();
    }

    i64 kept_pairs = self(i + 1);
    q.insert(distincts[i]);
    i64 erased_pairs = self(i + 1);
    q.erase(distincts[i]);

    return std::max(kept_pairs, erased_pairs);
  };

  i64 maximum_pairs = find_maximum_pairs();
  std::cout << maximum_pairs << '\n';
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
