#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k1, k2;
  std::cin >> n >> k1 >> k2;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  int k = k1 + k2;
  std::priority_queue<int> differences;
  for (int i = 0; i < n; ++i) {
    int d = std::abs(a[i] - b[i]);
    differences.push(d);
  }

  while (k-- > 0) {
    int d = differences.top();
    differences.pop();

    if (d == 0) {
      differences.push(1);
    } else {
      differences.push(d - 1);
    }
  }

  i64 result = 0;
  while (!differences.empty()) {
    i64 d = differences.top();
    differences.pop();
    result += d * d;
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
