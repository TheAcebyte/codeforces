#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> a(n);
  for (auto& cave : a) {
    int k;
    std::cin >> k;

    cave.resize(k);
    for (int j = 0; j < k; ++j) {
      int x;
      std::cin >> x;
      cave[j] = x - j;
    }
  }
  
  std::vector<int> max(n);
  for (int i = 0; i < n; ++i) {
    max[i] = a[i][0];
    int k = a[i].size();
    for (int j = 0; j < k; ++j) {
      max[i] = std::max(a[i][j], max[i]);
    }
  }

  std::vector<int> indices(n);
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }

  auto cmp = [&](int i, int j) { return max[i] < max[j]; };
  std::sort(indices.begin(), indices.end(), cmp);

  int result = 0;
  int carry = 0;
  for (int i : indices) {
    int k = a[i].size();
    result = std::max(1 + max[i] - carry, result);
    carry += k;
  }

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
