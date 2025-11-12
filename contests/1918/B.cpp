#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

void permute(std::vector<int> &array, const std::vector<int> &indices) {
  int n = array.size();
  std::vector<int> result(n);

  for (int i = 0; i < n; ++i) {
    result[i] = array[indices[i]];
  }

  array = std::move(result);
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  std::vector<int> indices(n);
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }

  auto cmp = [&a](int i, int j) { return a[i] < a[j]; };
  std::sort(indices.begin(), indices.end(), cmp);
  permute(a, indices);
  permute(b, indices);

  const char *separator = "";
  for (int x : a) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';

  separator = "";
  for (int x : b) {
    std::cout << separator << x;
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
