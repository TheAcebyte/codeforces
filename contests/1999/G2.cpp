#include <iostream>

void solve() {
  auto query = [](int a, int b) {
    int s;
    std::cout << "? " << a << ' ' << b << std::endl;
    std::cin >> s;
    return s;
  };

  auto submit = [](int x) {
    std::cout << "! " << x << std::endl;
  };

  int l = 2;
  int r = 999;
  while (r - l >= 3) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    int s = query(m1, m2);
    if (s == m1 * m2) {
      l = m2 + 1;
    } else if (s == m1 * (m2 + 1)) {
      l = m1 + 1;
      r = m2;
    } else {
      r = m1;
    }
  }

  if (l == r) {
    submit(l);
  } else if (r - l == 1) {
    int s = query(l, l);
    if (s == l * l) submit(r);
    else submit(l);
  } else {
    int s = query(l, l + 1);
    if (s == l * (l + 1)) submit(r);
    else if (s == l * (l + 2)) submit(l + 1);
    else submit(l);
  }
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
