#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

class distinct_counter {
private:
  std::map<int, int> distincts;

public:
  int count() { return distincts.size(); }
  bool has(int x) { return distincts.find(x) != distincts.end(); }
  bool has_multiple(int x) { return has(x) && distincts[x] > 1; }

  void increase(int x) { ++distincts[x]; }
  void decrease(int x) {
    assert(has(x));
    int frequency = --distincts[x];
    if (frequency == 0) {
      distincts.erase(x);
    }
  }
};

void solve() {
  int n, k, l, r;
  std::cin >> n >> k >> l >> r;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  i64 result = 0;
  distinct_counter distincts;
  int i = 0;
  int j = 0;
  while (j < n) {
    distincts.increase(a[j++]);
    while (j < n && distincts.count() < k) {
      distincts.increase(a[j++]);
    }

    if (distincts.count() < k) {
      break;
    }

    while (distincts.count() > k) {
      distincts.decrease(a[i++]);
    }

    int old_i = i;
    while (true) {
      while (distincts.has_multiple(a[i])) {
        distincts.decrease(a[i++]);
      }

      int x = std::max(j - r, old_i);
      int y = std::min(j - l, i);
      if (x <= y) {
        result += y - x + 1;
      }

      if (j >= n || !distincts.has(a[j])) {
        break;
      }

      distincts.increase(a[j++]);
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
