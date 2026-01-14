#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

u64 sum(int n, int m) {
  return (u64)(n + m) * (m - n + 1) / 2;
}

void solve() {
  int n, k;
  u64 x;
  std::cin >> n >> k >> x;

  u64 smallestSum = sum(1, k);
  u64 largestSum = sum(n - k + 1, n);
  if (x < smallestSum || x > largestSum) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
