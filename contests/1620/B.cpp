#include <algorithm>
#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  int w, h;
  std::cin >> w >> h;

  u64 result;
  int n, min, max;

  std::cin >> n;
  min = max = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (min == -1 || x < min) {
      min = x;
    }

    if (max == -1 || x > max) {
      max = x;
    }
  }
  result = (u64)(max - min) * h;

  std::cin >> n;
  min = max = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (min == -1 || x < min) {
      min = x;
    }

    if (max == -1 || x > max) {
      max = x;
    }
  }
  result = std::max((u64)(max - min) * h, result);

  std::cin >> n;
  min = max = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (min == -1 || x < min) {
      min = x;
    }

    if (max == -1 || x > max) {
      max = x;
    }
  }
  result = std::max((u64)(max - min) * w, result);

  std::cin >> n;
  min = max = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (min == -1 || x < min) {
      min = x;
    }

    if (max == -1 || x > max) {
      max = x;
    }
  }
  result = std::max((u64)(max - min) * w, result);

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
