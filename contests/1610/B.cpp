#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  int l = 0;
  int r = n - 1;
  while (l < r && a[l] == a[r]) {
    ++l;
    --r;
  }

  if (l >= r) {
    std::cout << "YES\n";
    return;
  }

  int l1 = l + 1;
  int r1 = r;
  while (l1 < r1) {
    if (a[l1] == a[r1]) {
      ++l1;
      --r1;
    } else if (a[l1] == a[l]) {
      ++l1;
    } else if (a[r1] == a[l]) {
      --r1;
    } else {
      break;
    }
  }

  if (l1 >= r1) {
    std::cout << "YES\n";
    return;
  }

  int l2 = l;
  int r2 = r - 1;
  while (l2 < r2) {
    if (a[l2] == a[r2]) {
      ++l2;
      --r2;
    } else if (a[l2] == a[r]) {
      ++l2;
    } else if (a[r2] == a[r]) {
      --r2;
    } else {
      break;
    }
  }

  if (l2 >= r2) {
    std::cout << "YES\n";
    return;
  }

  std::cout << "NO\n";
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
