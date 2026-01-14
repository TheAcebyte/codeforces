#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 n;
  std::cin >> n;

  int i = 1;
  while (n % i == 0) {
    ++i;
  } 

  int result = i - 1;
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
