#include <array>
#include <iostream>

#define N 20

int msb(int x) {
  int i = 0;
  while (x > 0) {
    if (x & 1) {
      return i;
    }

    x >>= 1;
    ++i;
  }

  return -1;
}

void solve() {
  int n, w;
  std::cin >> n >> w;

  std::array<int, N> bits;
  bits.fill(0);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    int index = msb(x);
    ++bits[index];
  }

  int height = 0;
  while (true) {
    int width = w;
    for (int i = N - 1; i >= 0; --i) {
      int x = 1 << i;
      while (bits[i] > 0 && width >= x) {
        --bits[i];
        width -= x;
      }
    }

    if (width == w) {
      break;
    }

    ++height;
  }

  int result = height;
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
