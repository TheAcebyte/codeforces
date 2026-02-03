#include <array>
#include <iostream>
#include <vector>

#define N 30

void solve() {
  int n;
  std::cin >> n;

  std::array<int, N> bits;
  bits.fill(0);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    for (int j = 0; j < N; ++j) {
      bits[j] += (x >> j) & 1;
    }
  }

  std::vector<int> divisors;
  for (int k = 1; k <= n; ++k) {
    bool valid = true;
    for (int count : bits) {
      if (count % k != 0) {
        valid = false;
        break;
      }
    }

    if (valid) {
      divisors.push_back(k);
    }
  }

  const char *separator = "";
  for (int d : divisors) {
    std::cout << separator << d;
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
