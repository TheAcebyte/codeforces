#include <cstdint>
#include <iostream>
#include <vector>

#define M 1000000007

using i64 = std::int64_t;

int factorial(int n) {
  i64 result = 1;
  for (int i = 2; i <= n; ++i) {
    result = (result * i) % M;
  }

  return result;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int full_and = a[0];
  for (int x : a) {
    full_and &= x;
  }

  int count = 0;
  for (int x : a) {
    if (x == full_and) {
      ++count;
    }
  }

  if (count < 2) {
    int result = 0;
    std::cout << result << '\n';
  } else {
    int result = (count * (((count - 1) * (i64)factorial(n - 2)) % M)) % M;
    std::cout << result << '\n';
  }
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
