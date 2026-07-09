#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> frequency(n + 1);
  int f = 0;
  int s = 0;
  int last_x = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x == last_x) {
      ++f;
    } else {
      if (f > 0) ++frequency[f];
      f = 1;
      ++s;
      last_x = x;
    }
  }

  if (f > 0) ++frequency[f];
  int last_s = -1;
  int result = 0;
  for (int f : frequency) {
    s -= f;
    if (n <= 0 && s == 0) break;
    if (n <= k && n % s == k % s && s != last_s) {
      ++result;
      last_s = s;
    }

    n -= s;
  }

  std::cout << result << '\n';
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
