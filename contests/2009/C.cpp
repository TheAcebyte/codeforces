#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int x, y, k;
    std::cin >> x >> y >> k;

    int stepsX = (x + k - 1) / k;
    int stepsY = (y + k - 1) / k;
    int result = stepsX > stepsY ? 2 * stepsX - 1 : 2 * stepsY;
    std::cout << result << '\n';
  }

  return 0;
}
