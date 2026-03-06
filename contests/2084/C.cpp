#include <iostream>
#include <utility>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  int identical_pairs = 0;
  std::vector<int> positions(n + 1);
  for (int i = 0; i < n; ++i) {
    positions[a[i]] = i;
    if (a[i] == b[i]) {
      ++identical_pairs;
    }
  }

  if (identical_pairs > n % 2) {
    std::cout << -1 << '\n';
    return;
  }

  std::vector<std::pair<int, int>> swaps;
  auto swap = [&](int i, int j) {
    if (i == j) {
      return;
    }

    std::swap(a[i], a[j]);
    std::swap(b[i], b[j]);
    std::swap(positions[a[i]], positions[a[j]]);
    swaps.push_back({i + 1, j + 1});
  };

  for (int x = 1; x <= n; ++x) {
    int i = positions[x];
    int j = positions[b[i]];
    if (a[i] != b[j]) {
      std::cout << -1 << '\n';
      return;
    }

    if (identical_pairs && a[i] == b[i]) {
      swap(i, n / 2);
    }
  }

  for (int x = 1; x <= n; ++x) {
    int i = positions[x];
    int j = positions[b[i]];
    swap(j, n - i - 1);
  }

  int swap_count = swaps.size();
  std::cout << swap_count << '\n';

  for (auto [i, j] : swaps) {
    std::cout << i << ' ' << j << '\n';
  }
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
