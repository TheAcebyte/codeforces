#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  i64 s = 0;
  int m1 = -1;
  int m2 = -1;
  for (int i = 0; i < n; ++i) {
    s += a[i];
    if (m1 == -1 || a[i] >= a[m1]) {
      m2 = m1;
      m1 = i;
    } else if (m2 == -1 || a[i] >= a[m2]) {
      m2 = i;
    }
  }

  std::vector<int> result;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    if ((i != m1 && s - a[i] == 2 * a[m1]) || (i != m2 && s - a[i] == 2 * a[m2])) {
      result.push_back(j);
    }
  }

  int k = result.size();
  std::cout << k << '\n';

  const char *separator = "";
  for (int j : result) {
    std::cout << separator << j;
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
  solve();

  return 0;
}
