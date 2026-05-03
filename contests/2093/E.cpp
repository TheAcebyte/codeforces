#include <iostream>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& x : a) { std::cin >> x; }

  auto is_valid_mex_partition = [&](int m) {
    int partitions = 0;
    int i = 0;
    while (i < n && partitions < k) {
      std::vector<bool> seen(m);
      int mex = 0;
      while (i < n && mex < m) {
        int x = a[i];
        if (x < m) {
          seen[x] = true;
        }

        while (mex < m && seen[mex]) {
          ++mex;
        }

        ++i;
      }

      partitions += mex == m;
    }

    return partitions == k;
  };

  int l = 0;
  int r = n;
  int mex;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (is_valid_mex_partition(m)) {
      mex = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  std::cout << mex << '\n';
}

int main() {
#ifdef DEBUG
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
