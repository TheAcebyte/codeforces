#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  int a, b, x, y, n;
  std::cin >> a >> b >> x >> y >> n;

  u64 aa = a;
  u64 ab = b;
  if (n <= a - x) {
    aa -= n;
  } else if (n + x - a <= b - y) {
    aa = x;
    ab -= n + x - a;
  } else {
    aa = x;
    ab = y;
  }

  u64 ba = a;
  u64 bb = b;
  if (n <= b - y) {
    bb -= n;
  } else if (n + y - b <= a - x) {
    bb = y;
    ba -= n + y - b;
  } else {
    bb = y;
    ba = x;
  }

  u64 result = std::min(aa * ab, ba * bb);
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
