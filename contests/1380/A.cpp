#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> prefix(n);
  prefix[0] = 0;
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1];
    if (a[i] < a[prefix[i - 1]]) {
      prefix[i] = i;
    }
  }

  std::vector<int> suffix(n);
  suffix[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    suffix[i] = suffix[i + 1];
    if (a[i] < a[suffix[i + 1]]) {
      suffix[i] = i;
    }
  }

  for (int j = 1; j < n - 1; ++j) {
    int i = prefix[j - 1];
    int k = suffix[j + 1];
    if (a[j] > a[i] && a[j] > a[k]) {
      ++i;
      ++j;
      ++k;
      std::cout << "YES\n";
      std::cout << i << ' ' << j << ' ' << k << '\n';
      return;
    }
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
