#include <algorithm>
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

  std::vector<int> indices(n);
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }

  auto cmp = [&a](int i, int j) { return a[i] < a[j]; };
  std::sort(indices.begin(), indices.end(), cmp);

  std::sort(a.begin(), a.end());
  std::vector<i64> prefix(n);
  prefix[0] = a[0];
  for (int i = 1; i < n; ++i) {
    prefix[i] = a[i] + prefix[i - 1];
  }

  std::vector<int> result(n);
  int j = indices[n - 1];
  result[j] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    int j = indices[i];
    int k = indices[i + 1];

    if (prefix[i] >= a[i + 1]) {
      result[j] = result[k];
    } else {
      result[j] = i;
    }
  }

  const char* separator = "";
  for (int x : result) {
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
