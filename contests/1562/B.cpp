#include <iostream>
#include <string>

bool isPrime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void solve() {
  int k;
  std::string n;
  std::cin >> k >> n;

  for (int i = 0; i < k; ++i) {
    int digit = n[i] - '0';
    if (digit == 1 || digit == 4 || digit == 6 || digit == 8 || digit == 9) {
      std::cout << 1 << '\n';
      std::cout << digit << '\n';
      return;
    }
  }

  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      int number = (n[i] - '0') * 10 + n[j] - '0';
      if (!isPrime(number)) {
        std::cout << 2 << '\n';
        std::cout << n[i] << n[j] << '\n';
        return;
      }
    }
  }
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
