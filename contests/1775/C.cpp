#include <cstdint>
#include <iostream>
#include <map>

using u64 = std::uint64_t;

void solve() {
  u64 n, x;
  std::cin >> n >> x;

  std::map<u64, u64> solutions{{n, n}};
  u64 b = 1;
  while (b <= n) {
    if ((n & b) == 0) {
      b <<= 1;
      continue;
    }

    while (n & b) {
      b <<= 1;
    }

    u64 mask = b - 1;
    u64 upper_n = n & ~mask;
    solutions[upper_n] = upper_n | b;
  }

  if (solutions.find(x) == solutions.end()) {
    std::cout << -1 << '\n';
    return;
  }

  u64 m = solutions[x];
  std::cout << m << '\n';
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
