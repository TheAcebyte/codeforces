#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

i64 kadane_sum(std::vector<int>::const_iterator start,
           std::vector<int>::const_iterator end) {
  i64 maximum = *start;
  i64 running = 0;
  while (start < end) {
    running += *start;
    maximum = std::max(running, maximum);
    if (running < 0) {
      running = 0;
    }

    ++start;
  }

  return maximum;
}

void solve() {
  int n;
  std::cin >> n;

  i64 s = 0;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    s += x;
  }

  i64 t = std::max(
    kadane_sum(a.begin(), a.end() - 1),
    kadane_sum(a.begin() + 1, a.end())
  );

  if (s > t) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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
