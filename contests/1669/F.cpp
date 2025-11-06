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

    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> weights[i];
    }

    std::vector<int> suffix(n);
    int ls = 0;

    for (int i = n - 1; i >= 0; --i) {
      suffix[i] = ls + weights[i];
      ls = suffix[i];
    }

    int pi = -1;
    int si = n;

    int prefix = 0;
    for (int p = 0; p < n; ++p) {
      prefix += weights[p];

      int sl = p + 1;
      int sr = n - 1;
      while (sl <= sr) {
        int sm = sl + (sr - sl) / 2;
        if (suffix[sm] == prefix) {
          pi = p;
          si = sm;
          break;
        } else if (suffix[sm] > prefix) {
          sl = sm + 1;
        } else {
          sr = sm - 1;
        }
      }
    }

    int result = pi + 1 + n - si;
    std::cout << result << '\n';
  }

  return 0;
}
