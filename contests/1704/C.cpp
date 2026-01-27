#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

int mod(int x, int m) {
  int result = x % m;
  return result < 0 ? result + m : result;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(m);
  for (int &x : a) {
    std::cin >> x;
    --x;
  }
  std::sort(a.begin(), a.end());

  std::vector<int> segments;
  segments.reserve(m);
  for (int i = 0; i < m - 1; ++i) {
    segments.push_back(a[i + 1] - a[i] - 1);
  }
  segments.push_back(mod(a[0] - a[m - 1] - 1, n));
  std::sort(segments.rbegin(), segments.rend());

  u64 saved = 0;
  int time = 0;
  for (int i = 0; i < m; ++i) {
    int length = segments[i] - 2 * time;
    if (length <= 0) {
      break;
    }

    if (length > 2) {
      saved += length - 1;
      time += 2;
    } else {
      ++saved;
      ++time;
    }
  }

  u64 result = n - saved;
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
