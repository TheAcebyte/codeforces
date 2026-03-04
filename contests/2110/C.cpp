#include <algorithm>
#include <iostream>
#include <vector>

struct interval {
  int l;
  int r;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> d(n);
  for (int &x : d) {
    std::cin >> x;
  }

  std::vector<interval> obstacles(n);
  for (auto &obstacle : obstacles) {
    std::cin >> obstacle.l >> obstacle.r;
  }

  int l = 0;
  int r = 0;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (d[i] == 1) {
      ++l;
      ++r;
    } else if (d[i] == -1) {
      ++r;
    }

    int l_new = std::max(l, obstacles[i].l);
    int r_new = std::min(r, obstacles[i].r);
    if (l_new > r_new) {
      std::cout << -1 << '\n';
      return;
    }

    int l_changes = l_new - l;
    while (l_changes > 0) {
      if (d[j] == -1) {
        d[j] = 1;
        --l_changes;
      }

      ++j;
    }

    int r_changes = r - r_new;
    while (r_changes > 0) {
      if (d[j] == -1) {
        d[j] = 0;
        --r_changes;
      }

      ++j;
    }

    l = l_new;
    r = r_new;
  }

  while (j < n) {
    if (d[j] == -1) {
      d[j] = 0;
    }

    ++j;
  }

  const char *separator = "";
  for (int x : d) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
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
