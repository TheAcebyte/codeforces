#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  int s = 0;
  for (int& x : a) {
    std::cin >> x;
    s ^= x;
  }

  if (n == 1) {
    std::cout << 0 << '\n';
    return;
  }

  if (s == 0) {
    std::cout << 1 << '\n';
    return;
  }

  int choices = 0;
  for (int x : a) {
    if ((s ^ x) < x) {
      ++choices;
    }
  }

  std::cout << choices << '\n';
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
