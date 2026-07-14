#include <iostream>
#include <utility>
#include <vector>

int conquer(std::vector<int>& a, int l, int r) {
  std::vector<int> b(r - l + 1);
  int m = l + (r - l) / 2;
  int i = l;
  int j = m + 1;
  int k = 0;
  int inversions = 0;
  while (i <= m && j <= r) {
    if (a[i] <= a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
      inversions += m - i + 1;
    }
  }

  while (i <= m) b[k++] = a[i++];
  while (j <= r) b[k++] = a[j++];
  for (int i = l; i <= r; ++i) {
    a[i] = b[i - l];
  }

  return inversions;
}

int divide(std::vector<int>& a, int l, int r) {
  if (l == r) return 0;
  int m = l + (r - l) / 2;
  int x = divide(a, l, m);
  int y = divide(a, m + 1, r);
  int z = conquer(a, l, r);
  return x + y + z;
}

int merge_sort(std::vector<int>& a) {
  int n = a.size();
  int inversions = divide(a, 0, n - 1);
  return inversions;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for (int& x : a) std::cin >> x;
  for (int& x : b) std::cin >> x;

  if (n == 1) {
    std::cout << (a[0] == b[0] ? "YES" : "NO") << '\n';
    return;
  }

  int x = merge_sort(a);
  if (x & 1) {
    std::swap(b[n - 1], b[n - 2]);
  }

  int y = merge_sort(b);
  std::cout << (a == b && y % 2 == 0 ? "YES" : "NO") << '\n';
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
