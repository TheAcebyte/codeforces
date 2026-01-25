#include <iostream>
#include <vector>

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (int& b : a) {
    std::cin >> b;
  }

  std::vector<int> x;
  x.reserve(q);

  int first;
  std::cin >> first;
  x.push_back(first);

  for (int i = 1; i < q; ++i) {
    int y;
    std::cin >> y;

    if (y < x.back()) {
      x.push_back(y);
    }
  }

  for (int& b : a) {
    for (int y : x) {
      int power = 1 << y;
      if (b % power == 0) {
        b += power >> 1;
      }
    }
  }

  const char* separator = "";
  for (int b : a) {
    std::cout << separator << b;
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
