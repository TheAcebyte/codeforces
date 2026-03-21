#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  int s = 0;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    s ^= x;
  }

  if (s == 0) {
    std::cout << "YES\n";
    return;
  }

  int i = 0;
  int first = 0;
  while (i < n && first != s) {
    first ^= a[i];
    ++i;
  }

  if (i >= n) {
    std::cout << "NO\n";
    return;
  }

  int second = 0;
  while (i < n && second != s) {
    second ^= a[i];
    ++i;
  }

  if (i >= n) {
    std::cout << "NO\n";
    return;
  }

  int third = 0;
  while (i < n) {
    third ^= a[i];
    ++i;
  }

  if (third != s) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
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
