#include <iostream>
#include <vector>

int mod(int x, int m) {
  int result = x % m;
  return result < 0 ? result + m : result;
}

void solve() {
  int n, l, r;
  std::cin >> n >> l >> r;
  
  std::vector<int> a(n);
  for (int i = 1; i <= n; ++i) {
    int j = i - 1;
    int x = l + mod(i - l, i);
    if (x > r) {
      std::cout << "NO\n";
      return;
    }

    a[j] = x;
  }

  std::cout << "YES\n";
  const char* separator = "";
  for (int x : a) {
    std::cout << separator << x;
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
