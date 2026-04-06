#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(m);
  for (int &x : b) {
    std::cin >> x;
  }

  std::string s;
  std::cin >> s;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  std::vector<std::vector<int>> left_kills(k + 1);
  std::vector<std::vector<int>> right_kills(k + 1);

  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    while (j < m && b[j] < a[i]) {
      ++j;
    }

    int old_i = i;
    while (i < n && (j == m || a[i] < b[j])) {
      ++i;
    }

    for (int x = old_i; x < i; ++x) {
      if (j > 0) {
        int l = a[x] - b[j - 1];
        if (l <= k) {
          left_kills[l].push_back(x);
        }
      }

      if (j < m) {
        int r = b[j] - a[x];
        if (r <= k) {
          right_kills[r].push_back(x);
        }
      }
    }
  }

  std::vector<bool> alive(n, true);
  int l = 0;
  int r = 0;
  int result = n;
  for (int i = 0; i < k; ++i) {
    if (s[i] == 'L') {
      ++l;
      --r;
    } else {
      ++r;
      --l;
    }

    if (l >= 0) {
      for (int x : left_kills[l]) {
        if (alive[x]) {
          --result;
        }

        alive[x] = false;
      }

      left_kills[l].clear();
    }

    if (r >= 0) {
      for (int x : right_kills[r]) {
        if (alive[x]) {
          --result;
        }

        alive[x] = false;
      }

      right_kills[r].clear();
    }

    std::cout << result << " \n"[i == k - 1];
  }
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
