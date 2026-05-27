#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  auto query = [](int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;
    int m = r - l + 1;
    std::vector<int> a(m);
    for (int& x : a) { std::cin >> x; }
    return a;
  };

  auto submit = [](int x) {
    std::cout << "! " << x << std::endl;
  };

  auto contains_fixed_point = [&](int l, int r) {
    auto a = query(l, r);
    int count = 0;
    for (int x : a) {
      count += (x >= l && x <= r);
    }

    return count & 1;
  };

  int x;
  int low = 1;
  int high = n;
  while (low <= high) {
    int m = low + (high - low) / 2;
    if (contains_fixed_point(1, m)) {
      x = m;
      high = m - 1;
    } else {
      low = m + 1;
    }
  }

  submit(x);
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
