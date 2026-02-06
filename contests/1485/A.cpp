#include <iostream>
#include <limits>

void solve() {
  int a, b;
  std::cin >> a >> b;

  int db = 0;
  if (b == 1) {
    ++db;
  }

  int result = std::numeric_limits<int>::max();
  while (true) {
    int x = a;
    int y = b + db;
    int i = 0;
    while (x > 0) {
      x /= y;
      ++i;
    }

    int operations = i + db;
    if (operations > result) {
      break;
    }

    result = operations;
    ++db;
  }

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
