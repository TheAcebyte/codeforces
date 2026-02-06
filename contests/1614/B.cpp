#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> indices(n);
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }

  auto cmp = [&a](int i, int j) { return a[i] > a[j]; };
  std::sort(indices.begin(), indices.end(), cmp);

  std::vector<int> distances(n + 1);
  distances[0] = 0;

  u64 result = 0;
  int i = 0;
  int x = 1;
  while (i < n) {
    int j = indices[i];
    result += 2ULL * a[j] * x;
    distances[j + 1] = x;
    ++i;

    if (i >= n) {
      break;
    }

    int k = indices[i];
    result += 2ULL * a[k] * x;
    distances[k + 1] = -x;
    ++i;
    ++x;
  }

  const char* separator = "";
  std::cout << result << '\n';
  for (int distance : distances) {
    std::cout << separator << distance;
    separator = " ";
  }
  std::cout << '\n';
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
