#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using i64 = std::int64_t;

class fraction {
private:
  i64 p;
  i64 q;

public:
  fraction(i64 p, i64 q) : p(p), q(q) { assert(q != 0); }

  bool operator<(const fraction &other) const {
    i64 l = p * other.q;
    i64 r = q * other.p;
    if (q * other.q < 0) {
      std::swap(l, r);
    }

    return l < r;
  }

  bool operator==(const fraction &other) const {
    return p * other.q == q * other.p;
  }
};

void setmax(int &max, int x) { max = std::max(x, max); }

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

  std::map<fraction, int> d;
  int zero_pairs = 0;
  int max_frequency = 0;
  for (int i = 0; i < n; ++i) {
    int p = -b[i];
    int q = a[i];
    if (q != 0) {
      fraction f(p, q);
      setmax(max_frequency, ++d[f]);
    } else if (p == 0) {
      ++zero_pairs;
    }
  }

  int result = zero_pairs + max_frequency;
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
