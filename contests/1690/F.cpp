#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    p[i] = x - 1;
  }

  auto get_min_rotations = [](const std::string& s) {
    int n = s.length();
    for (int k = 1; k < n; ++k) {
      if (n % k > 0) continue;
      bool ok = true;
      for (int i = k; i < n; ++i) {
        if (s[i] != s[i - k]) {
          ok = false;
          break;
        }
      }

      if (ok) return k;
    }

    return n;
  };

  i64 operations = 1;
  std::vector<bool> seen(n);
  for (int i = 0; i < n; ++i) {
    if (seen[i]) continue;
    std::string t;
    int j = i;
    do {
      t.push_back(s[j]);
      j = p[j];
    } while (j != i);

    int rotations = get_min_rotations(t);
    operations = std::lcm(rotations, operations);
    seen[i] = true;
  }

  std::cout << operations << '\n';
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
