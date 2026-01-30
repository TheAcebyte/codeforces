#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  for (int k = 2; k * k < n; ++k) {
    int count = 1 + k + k * k;
    int power = k * k;
    while (count < n) {
      power *= k;
      count += power;
    }
 
    if (count == n) {
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
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
