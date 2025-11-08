#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> getMaxIndices(const std::vector<int> &array, int n) {
  std::vector<int> max(n, -1);
  for (int i = 0; i < array.size(); ++i) {
    for (int j = 0; j < n; ++j) {
      if (max[j] == -1) {
        max[j] = i;
        break;
      }

      if (array[i] > array[max[j]]) {
        for (int k = n - 1; k > j; --k) {
          max[k] = max[k - 1];
        }
        max[j] = i;
        break;
      }
    }
  }

  return max;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }

    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> c[i];
    }

    std::vector<int> ai = getMaxIndices(a, 3);
    std::vector<int> bi = getMaxIndices(b, 3);
    std::vector<int> ci = getMaxIndices(c, 3);

    int result = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (bi[j] == ai[i]) {
          continue;
        }

        for (int k = 0; k < 3; ++k) {
          if (ci[k] == bi[j] || ci[k] == ai[i]) {
            continue;
          }

          int sum = a[ai[i]] + b[bi[j]] + c[ci[k]];
          result = std::max(sum, result);
        }
      }
    }

    std::cout << result << '\n';
  }

  return 0;
}
