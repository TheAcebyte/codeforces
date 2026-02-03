#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> k(n);
  for (int &x : k) {
    std::cin >> x;
    --x;
  }
  std::sort(k.rbegin(), k.rend());

  std::vector<int> c(m);
  for (int &x : c) {
    std::cin >> x;
  }

  i64 result = 0;
  int i = 0;
  int j = 0;
  while (i < n) {
    if (k[i] >= j) {
      result += c[j];
      ++j;
    } else {
      result += c[k[i]];
    }

    ++i;
  }

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
