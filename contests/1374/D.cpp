#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

int mod(int x, int m) {
  int result = x % m;
  return result < 0 ? result + m : result;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a;
  a.reserve(n);

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    int y = mod(-x, k);
    if (y == 0) {
      continue;
    }

    a.push_back(y);
  }
  std::sort(a.begin(), a.end());

  int m = a.size();
  if (m == 0) {
    int result = 0;
    std::cout << result << '\n';
    return;
  }

  int longest_sequence_value = 0;
  int longest_sequence_length = 0;
  for (int i = 0; i < m; ++i) {
    int sequence_value = a[i];
    int sequence_length = 1;
    while (i < m - 1 && a[i + 1] == a[i]) {
      ++sequence_length;
      ++i;
    }

    if (sequence_length >= longest_sequence_length) {
      longest_sequence_value = sequence_value;
      longest_sequence_length = sequence_length;
    }
  }

  int v = longest_sequence_value;
  int l = longest_sequence_length;
  i64 result = (i64)k * (l - 1) + v + 1;
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
