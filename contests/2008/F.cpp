#include <cstdint>
#include <iostream>
#include <vector>

#define M 1000000007

using i64 = std::int64_t;

int binary_exp(i64 x, i64 n) {
  i64 result = 1;
  while (n > 0) {
    if (n & 1) {
      result = (result * x) % M;
    }

    x = (x * x) % M;
    n >>= 1;
  }

  return result;
}

void solve() {
  i64 n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<i64> suffix(n);
  suffix[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suffix[i] = (a[i] + suffix[i + 1]) % M;
  }

  i64 p = 0;
  for (int i = 0; i < n - 1; ++i) {
    p = (p + (a[i] * suffix[i + 1]) % M) % M;
  }

  i64 q = (n * (n - 1) / 2) % M;
  int result = (p * binary_exp(q, M - 2)) % M;
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
