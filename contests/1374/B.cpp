#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int threes = 0;
  while (n % 3 == 0) {
    n /= 3;
    ++threes;
  }

  int twos = 0;
  while (n % 2 == 0) {
    n /= 2;
    ++twos;
  }

  if (n > 1 || twos > threes) {
    std::cout << -1 << '\n';
    return;
  }

  int result = 2 * threes - twos;
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
