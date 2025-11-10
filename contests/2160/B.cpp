#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  u64 last = 0;
  for (int i = 0; i < n; ++i) {
    u64 b;
    std::cin >> b;

    int di = b - last;
    if (i - di >= 0) {
      a[i] = a[i - di];
    } else {
      a[i] = i + 1;
    }

    last = b;
  }

  const char* separator = "";
  for (int i = 0; i < n; ++i) {
    std::cout << separator << a[i];
    separator = " ";
  }
  std::cout << '\n';
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
