#include <iostream>
#include <vector>

int get_max(const std::vector<int> &a) {
  int max = a[0];
  for (int x : a) {
    max = std::max(x, max);
  }

  return max;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  int operations = 0;
  std::vector<int> values;
  int value = (get_max(a) + 1) / 2;
  while (value > 0 && operations < 40) {
    int max = 0;
    for (int &x : a) {
      x = std::abs(x - value);
      max = std::max(x, max);
    }

    values.push_back(value);
    value = (max + 1) / 2;
    ++operations;
  }

  for (int x : a) {
    if (x != 0) {
      std::cout << -1 << '\n';
      return;
    }
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
