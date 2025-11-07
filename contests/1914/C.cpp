#include <iostream>
#include <vector>

int solve(const std::vector<int> &a, const std::vector<int> &b, int k, int i,
          int maxSubsequent) {
  if (k == 0) {
    return 0;
  }

  if (i >= a.size()) {
    return k * maxSubsequent;
  }

  return std::max(k * maxSubsequent,
                  a[i] +
                      solve(a, b, k - 1, i + 1, std::max(b[i], maxSubsequent)));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }

    std::cout << solve(a, b, k, 0, 0) << '\n';
  }

  return 0;
}
