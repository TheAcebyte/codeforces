#include <iostream>
#include <vector>

struct interval {
  int l;
  int r;
};

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> prefix_ones(n + 1);
  for (int i = 1; i <= n; ++i) {
    prefix_ones[i] = a[i] + prefix_ones[i - 1];
  }

  std::vector<int> nearest_left_adjacents(n + 1);
  for (int i = 1; i <= n; ++i) {
    nearest_left_adjacents[i] = nearest_left_adjacents[i - 1];
    if (i < n && a[i] == a[i + 1]) {
      nearest_left_adjacents[i] = i;
    }
  }

  while (q-- > 0) {
    int l, r;
    std::cin >> l >> r;

    int m = r - l + 1;
    int ones = prefix_ones[r] - prefix_ones[l - 1];
    if (m % 3 != 0 || ones % 3 != 0) {
      std::cout << -1 << '\n';
      continue;
    }

    int i = nearest_left_adjacents[r - 1];
    int operations = m / 3 + (i < l);
    std::cout << operations << '\n';
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
