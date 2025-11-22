#include <iostream>
#include <vector>

int ceil(int a, int b) {
  int result = a / b;
  if (a % b != 0 && ((a > 0 && b > 0) || (a < 0 && b < 0))) {
    ++result;
  }

  return result;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  int max = 0;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    max = std::max(x, max);
  }

  int commonStart = max;
  int commonEnd = max + k;
  for (int x : a) {
    int start = x + 2 * k * (ceil(commonEnd - x, 2 * k) - 1);
    if (start >= commonStart) {
      commonStart = start;
    }
  }

  for (int x : a) {
    int start = x + 2 * k * (ceil(commonEnd - x, 2 * k) - 1);
    int end = start + k;
    if (end <= commonStart) {
      std::cout << -1 << '\n';
      return;
    }
  }

  std::cout << commonStart << '\n';
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
