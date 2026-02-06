#include <array>
#include <iostream>

#define N 300000

std::array<int, N> xors{0};

void solve() {
  int a, b;
  std::cin >> a >> b;

  int result = a;
  int x = xors[a - 1];
  if (x != b) {
    ++result;
    if ((x ^ b) == a) {
      ++result;
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  for (int i = 1; i < N; ++i) {
    xors[i] = i ^ xors[i - 1];
  }

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
