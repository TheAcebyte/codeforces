#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int& x : b) {
    std::cin >> x;
  }

  int max = std::numeric_limits<int>::min();
  for (int i = 0; i < n; ++i) {
    max = std::max(a[i] - b[i], max);
  }

  std::vector<int> indices;
  for (int i = 0; i < n; ++i) {
    if (a[i] - b[i] == max) {
      indices.push_back(i + 1);
    }
  }


  std::cout << indices.size() << '\n';
  const char* separator = "";
  for (int i : indices) {
    std::cout << separator << i;
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
