#include <cstdint>
#include <iostream>
#include <string>

#define M 998244353

using i64 = std::int64_t;

int factorial(int n) {
  i64 result = 1;
  for (int i = 2; i <= n; ++i) {
    result = (result * i) % M;
  }

  return result;
}

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  i64 result = 1;
  int i = 0;
  int k = 0;
  while (i < n) {
    int start = i;
    while (i < n - 1 && s[i + 1] == s[i]) {
      ++i;
    }

    int length = i - start + 1;
    result = (result * length) % M;

    ++k;
    ++i;
  }

  result = (result * factorial(n - k)) % M;
  std::cout << n - k << ' ' << result << '\n';
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
