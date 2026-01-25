#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define MOD 1000000007

using i64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }
  std::sort(b.begin(), b.end());

  i64 result = 0;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n && a[i] > b[j]) {
      ++j;
    }

    result = (result * (j - i)) % MOD;
  }

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
