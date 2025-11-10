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

  int count[10]{0};
  for (int i = 0; i < k; ++i) {
    int digit = n[i] - '0';
    ++count[digit];

    if (digit == 1 || digit == 4 || digit == 6 || digit == 8 || digit == 9) {
      std::cout << 1 << '\n';
      std::cout << digit << '\n';
      return;
    }
  }

  for (int i = 0; i < 10; ++i) {
    if (count[i] == 2) {
      std::cout << 2 << '\n';
      std::cout << i << i << '\n';
      return;
    }
  }

  if (k == 2) {
    std::cout << 2 << '\n';
    std::cout << n << '\n';
    return;
  }

  int a = n[0] - '0';
  int b = n[1] - '0';
  int c = n[2] - '0';

  int ab = 10 * a + b;
  int ac = 10 * a + c;
  int bc = 10 * b + c;

  if (!isPrime(ab)) {
    std::cout << 2 << '\n';
    std::cout << ab << '\n';
    return;
  }

  if (!isPrime(ac)) {
    std::cout << 2 << '\n';
    std::cout << ac << '\n';
    return;
  }

  if (!isPrime(bc)) {
    std::cout << 2 << '\n';
    std::cout << bc << '\n';
    return;
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
