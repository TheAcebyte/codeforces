#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  auto query = [](int i, int j) {
    int m;
    std::cout << "? " << i + 1 << ' ' << j + 1 << std::endl;
    std::cin >> m;
    return m;
  };

  std::vector<int> p(n, n);
  int l = 0;
  int r = n - 1;
  while (l < r) {
    int r1 = query(l, r);
    int r2 = query(r, l);
    if (r1 > r2) {
      p[l++] = r1;
    } else {
      p[r--] = r2;
    }
  }

  std::cout << "!";
  for (int x : p) std::cout << ' ' << x;
  std::cout << std::endl;
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
