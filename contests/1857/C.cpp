#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    int m = n * (n - 1) / 2;
    std::vector<int> array(m);
    int max = std::numeric_limits<int>::min();

    for (int i = 0; i < m; ++i) {
      std::cin >> array[i];
      max = std::max(array[i], max);
    }

    std::sort(array.begin(), array.end());

    int i = 0;
    int step = n - 1;
    const char *separator = "";
    while (step > 0) {
      std::cout << separator << array[i];
      i += step;
      --step;
      separator = " ";
    }
    std::cout << separator << max << '\n';
  }

  return 0;
}
