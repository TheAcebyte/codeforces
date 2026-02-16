#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

struct pair {
  int boy;
  int girl;
};

void solve() {
  int a, b, k;
  std::cin >> a >> b >> k;

  std::vector<pair> pairs(k);
  std::vector<int> boys(a);
  std::vector<int> girls(b);

  for (auto &pair : pairs) {
    std::cin >> pair.boy;
    --pair.boy;
    ++boys[pair.boy];
  }

  for (auto &pair : pairs) {
    std::cin >> pair.girl;
    --pair.girl;
    ++girls[pair.girl];
  }

  i64 result = 0;
  for (auto pair : pairs) {
    --k;
    --boys[pair.boy];
    --girls[pair.girl];
    result += k - boys[pair.boy] - girls[pair.girl];
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
