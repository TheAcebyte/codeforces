#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

template <typename T> class sparse_table {
private:
  int n;
  std::vector<int> log2;
  std::vector<std::vector<T>> data;

  void precompute_log2() {
    log2[0] = log2[1] = 0;
    for (int i = 2; i <= n; ++i) {
      log2[i] = log2[i >> 1] + 1;
    }
  }

public:
  sparse_table(const std::vector<T> &v) : n(v.size()), log2(n + 1) {
    precompute_log2();
    int m = log2[n];
    data = std::vector(m + 1, std::vector<T>(n));
    std::copy(v.begin(), v.end(), data.front().begin());
    for (int k = 1; k <= m; ++k) {
      for (int i = 0; i + (1 << k) <= n; ++i) {
        int j = i + (1 << (k - 1));
        data[k][i] = std::min(data[k - 1][i], data[k - 1][j]);
      }
    }
  }

  T query(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int k = log2[r - l + 1];
    int i = r - (1 << k) + 1;
    T result = std::min(data[k][l], data[k][i]);
    return result;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    int h;
    std::cin >> h;
    a[i] = n - h;
  }

  sparse_table t(a);
  int q;
  std::cin >> q;
  while (q-- > 0) {
    int xs, ys, xf, yf, k;
    std::cin >> xs >> ys >> xf >> yf >> k;
    xs = n - xs;
    xf = n - xf;
    --ys; --yf;

    int l = std::min(ys, yf);
    int r = std::max(ys, yf);
    int m = t.query(l, r);
    if ((xs - xf) % k == 0 && (ys - yf) % k == 0 && m > xs % k) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
