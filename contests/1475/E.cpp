#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr int N = 1000;
constexpr int M = 1e9 + 7;

std::vector<i64> factorials(N + 1);
void precompute_factorials() {
  factorials[0] = 1;
  for (int i = 1; i <= N; ++i) {
    factorials[i] = (i * factorials[i - 1]) % M;
  }
}

i64 mod_inverse(i64 x) {
  i64 y = 1;
  i64 n = M - 2;
  while (n > 0) {
    if (n & 1) y = (y * x) % M;
    x = (x * x) % M;
    n >>= 1;
  }

  return y;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;
  std::sort(a.rbegin(), a.rend());

  int x = a[k - 1];
  int i = k - 1;
  while (i >= 0 && a[i] == x) {
    --i;
  }

  int j = k - 1;
  while (j < n && a[j] == x) {
    ++j;
  }

  int m = j - i - 1;
  int s = k - 1 - i;
  i64 p = factorials[m];
  i64 q = (factorials[s] * factorials[m - s]) % M;
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
