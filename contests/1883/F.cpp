#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> suffix(n + 1);
  suffix[n] = 0;

  std::set<int> seenAfter;
  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = suffix[i + 1];
    if (!seenAfter.count(a[i])) {
      ++suffix[i];
      seenAfter.insert(a[i]);
    }
  }

  i64 result = 0;
  std::set<int> seenBefore;
  for (int i = 0; i < n; ++i) {
    if (!seenBefore.count(a[i])) {
      result += suffix[i];
      seenBefore.insert(a[i]);
    }
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
