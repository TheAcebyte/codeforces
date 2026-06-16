#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

constexpr i64 N = 3000;
constexpr i64 M = 998244353;

struct fraction {
  int p, q;

  bool operator<(const fraction& other) const {
    return (i64)p * other.q < (i64)other.p * q;
  };
};

struct frequency {
  int x, c;
};

i64 fact[N + 1];
void precompute_factorials() {
  fact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact[i] = (fact[i - 1] * i) % M;
  }
}

i64 mod_inverse(i64 x) {
  i64 p = M - 2;
  i64 y = 1;
  while (p > 0) {
    if (p & 1) y = (y * x) % M;
    x = (x * x) % M;
    p >>= 1;
  }

  return y;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::vector<int> b(n);
  for (int& x : b) std::cin >> x;

  std::vector<fraction> a_frac;
  a_frac.reserve((i64)n * (n - 1) / 2);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      a_frac.push_back({a[j], a[i]});
    }
  }

  std::sort(a_frac.begin(), a_frac.end());

  std::map<int, int> b_freq;
  for (int x : b) ++b_freq[x];

  i64 c = 1;
  for (auto [x, cx] : b_freq) {
    c = (c * fact[cx]) % M;
  }

  i64 permutations = (fact[n - 2] * mod_inverse(c)) % M;
  i64 inversions = 0;
  for (auto [x, cx] : b_freq) {
    for (auto [y, cy] : b_freq) {
      if (x == y && cx == 1) continue;

      fraction f{x, y};
      int i = std::lower_bound(a_frac.begin(), a_frac.end(), f) - a_frac.begin();
      i64 p = permutations;
      if (x == y) {
        p = (p * cx * (cx - 1)) % M;
      } else {
        p = (p * cx * cy) % M;
      }

      inversions = (inversions + i * p) % M;
    }
  }

  i64 p = inversions;
  i64 q = (permutations * n * (n - 1)) % M;
  i64 result = (p * mod_inverse(q)) % M;
  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  precompute_factorials();

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
