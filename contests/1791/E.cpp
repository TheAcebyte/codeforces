#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> array[i];
    }

    i64 x = array[0];
    i64 y = -array[0];
    for (int i = 1; i < n; ++i) {
      i64 newX = std::max(array[i] + x, -array[i] + y);
      i64 newY = std::max(-array[i] + x, array[i] + y);
      std::swap(x, newX);
      std::swap(y, newY);
    }

    std::cout << x << '\n';
  }

  return 0;
}
