#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n * k);
  for (int &x : a) {
    std::cin >> x;
  }

  u64 result = 0;
  int step = n / 2 + 1;
  int j = n * k;
  for (int i = 0; i < k; ++i) {
    j -= step;
    result += a[j];
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
