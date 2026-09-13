#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

struct problem {
  int a, b;
};

void solve() {
  i64 n;
  std::cin >> n;

  std::vector<problem> problems(n);
  for (auto& p : problems) {
    std::cin >> p.a >> p.b;
    --p.a; --p.b;
  }

  std::vector<i64> a(n), b(n);
  for (auto p : problems) {
    ++a[p.a];
    ++b[p.b];
  }

  i64 bad_triplets = 0;
  for (auto p : problems) {
    bad_triplets += (a[p.a] - 1) * (b[p.b] - 1);
  }

  i64 good_triplets = n * (n - 1) * (n - 2) / 6 - bad_triplets;
  std::cout << good_triplets << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
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
