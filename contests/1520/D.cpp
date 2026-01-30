#include <cstdint>
#include <iostream>
#include <map>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  u64 result = 0;
  std::map<int, int> differences;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;

    int difference = x - i;
    result += differences[difference]++;
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
