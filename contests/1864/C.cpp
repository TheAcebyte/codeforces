#include <iostream>
#include <vector>

void solve() {
  int x;
  std::cin >> x;

  std::vector<int> values;
  int b = x;
  int i = 0;
  while (b > 1) {
    if (b & 1) {
      values.push_back(x);
      x &= ~(1 << i);
    }

    b >>= 1;
    ++i;
  }

  while (x > 0) {
    values.push_back(x);
    x >>= 1;
  }

  std::cout << values.size() << '\n';
  const char *separator = "";
  for (int value : values) {
    std::cout << separator << value;
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
