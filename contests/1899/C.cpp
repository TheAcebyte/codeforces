#include <iostream>

bool parity(int x) {
  int result = x % 2;
  return result < 0 ? result + 2 : result;
}

void solve() {
  int n;
  std::cin >> n;

  int first;
  std::cin >> first;

  int sum = first;
  int last = first;
  int result = first;
  for (int i = 1; i < n; ++i) {
    int x;
    std::cin >> x;

    if (sum < 0 || parity(x) == parity(last)) {
      sum = 0;
    }

    sum += x;
    last = x;
    result = std::max(sum, result);
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
