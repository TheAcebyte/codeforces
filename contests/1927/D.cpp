#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> neighbor(n);
  neighbor[0] = -1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      neighbor[i] = i - 1;
    } else {
      neighbor[i] = neighbor[i - 1];
    }
  }

  int q;
  std::cin >> q;
  while (q-- > 0) {
    int l, r;
    std::cin >> l >> r;
    --l;
    --r;

    if (neighbor[r] < l) {
      std::cout << "-1 -1\n";
    } else {
      std::cout << neighbor[r] + 1 << ' ' << r + 1 << '\n';
    }
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
