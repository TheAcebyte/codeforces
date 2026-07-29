#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

constexpr i64 M = 1e9 + 7;

i64 modinv(i64 x) {
  i64 y = 1;
  i64 n = M - 2;
  while (n > 0) {
    if (n & 1) {
      y = (y * x) % M;
    }

    x = (x * x) % M;
    n >>= 1;
  }

  return y;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::map<int, i64> frequency_map;
  for (int i = 0; i < n; ++i) {
    int x; 
    std::cin >> x;
    ++frequency_map[x];
  }

  std::vector<int> b;
  std::vector<i64> c;
  for (auto [x, f] : frequency_map) {
    b.push_back(x);
    c.push_back(f);
  }

  int d = b.size();
  std::vector<i64> p(d);
  p[0] = c[0];
  for (int i = 1; i < d; ++i) {
    p[i] = (c[i] * p[i - 1]) % M;
  }

  auto range_product = [&](int l, int r) {
    i64 result = p[r];
    if (l > 0) {
      result = (result * modinv(p[l - 1])) % M;
    }

    return result;
  };

  i64 dances = 0;
  for (int i = 0; i <= d - m; ++i) {
    if (b[i + m - 1] == b[i] + m - 1) {
      dances = (dances + range_product(i, i + m - 1)) % M;
    }
  }

  std::cout << dances << '\n';
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
