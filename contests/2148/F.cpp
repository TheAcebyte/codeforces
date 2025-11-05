#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    int kmax = 0;
    std::vector<std::vector<int>> grid(n);
    for (int i = 0; i < n; ++i) {
      int k;
      std::cin >> k;

      std::vector<int> row(k);
      for (int j = 0; j < k; ++j) {
        std::cin >> row[j];
      }

      grid[i] = std::move(row);
      kmax = std::max(k, kmax);
    }

    int length = 0;
    const char *separator = "";
    while (length < kmax) {
      const std::vector<int> *min = NULL;
      for (const auto &row : grid) {
        if (row.size() <= length) {
          continue;
        }

        if (min == NULL) {
          min = &row;
          continue;
        }

        if (std::lexicographical_compare(row.begin() + length, row.end(),
                                         min->begin() + length, min->end())) {
          min = &row;
        }
      }

      for (int i = length; i < min->size(); ++i) {
        std::cout << separator << (*min)[i];
        separator = " ";
      }

      length = min->size();
    }

    std::cout << '\n';
  }

  return 0;
}
