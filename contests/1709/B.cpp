#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<u64> prefix(n);
  prefix[0] = 0;
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1];
    if (a[i] < a[i - 1]) {
      prefix[i] += a[i - 1] - a[i];
    }
  }

  std::vector<u64> suffix(n);
  suffix[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    suffix[i] = suffix[i + 1];
    if (a[i] < a[i + 1]) {
      suffix[i] += a[i + 1] - a[i];
    }
  }

  while (m-- > 0) {
    int s, t;
    std::cin >> s >> t;
    --s;
    --t;

    if (s <= t) {
      u64 damage = prefix[t] - prefix[s];
      std::cout << damage << '\n';
    } else {
      u64 damage = suffix[t] - suffix[s];
      std::cout << damage << '\n';
    }
  }
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
