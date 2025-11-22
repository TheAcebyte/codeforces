#include <iostream>

int msb(int a) {
  if (a == 0) {
    return -1;
  }

  int i = 0;
  while (a > 1) {
    a >>= 1;
    ++i;
  }

  return i;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  int high = n + m;
  int bit = msb(n ^ high);
  int low = n - m;
  if (low >= 0) {
    bit = std::max(msb(n ^ low), bit);
  }

  int result = n | ((1 << (bit + 1)) - 1);
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
