#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    x %= k;
    if (x == 0) {
      x = k;
    }
  }

  std::vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    order[i] = i;
  }

  auto cmp = [&](int i, int j) { return a[i] > a[j]; };
  std::stable_sort(order.begin(), order.end(), cmp);

  const char *separator = "";
  for (int index : order) {
    std::cout << separator << index + 1;
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
