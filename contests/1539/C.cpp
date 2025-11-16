#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using u64 = std::uint64_t;

template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void solve() {
  int n;
  u64 k, x;
  std::cin >> n >> k >> x;

  std::vector<u64> a(n);
  for (u64 &s : a) {
    std::cin >> s;
  }
  std::sort(a.begin(), a.end());

  u64 groups = 1;
  min_heap<u64> gaps;
  for (int i = 1; i < n; ++i) {
    u64 difference = a[i] - a[i - 1];
    if (difference > x) {
      u64 required = (difference + x - 1) / x - 1;
      gaps.push(required);
      ++groups;
    }
  }

  while (!gaps.empty() && k >= gaps.top()) {
    k -= gaps.top();
    gaps.pop();
    --groups;
  }

  u64 result = groups;
  std::cout << result << '\n';
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
