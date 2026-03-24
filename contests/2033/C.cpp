#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int l = 0;
  int r = n - 1;
  int disturbance = 0;
  while (r - l > 1) {
    if (a[l] == a[l + 1] && a[r] == a[r - 1] && a[l] == a[r]) {
      disturbance += 2;
    } else if ((a[l] == a[l + 1] && a[l] == a[r]) ||
               (a[l] == a[l + 1] && a[l] == a[r - 1]) ||
               (a[r] == a[r - 1] && a[l] == a[r]) ||
               (a[r] == a[r - 1] && a[l + 1] == a[r])) {
      ++disturbance;
    }

    ++l;
    --r;
  }

  if (l < r && a[l] == a[r]) {
    ++disturbance;
  }

  int result = disturbance;
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
