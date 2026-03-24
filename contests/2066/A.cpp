#include <algorithm>
#include <iostream>
#include <vector>

int mex(const std::vector<int> &a) {
  int n = a.size();
  std::vector<int> seen(n + 1);
  for (int x : a) {
    if (x <= n) {
      seen[x] = true;
    }
  }

  for (int x = 1; x <= n; ++x) {
    if (!seen[x]) {
      return x;
    }
  }

  return n + 1;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i];
  }

  auto query = [](int i, int j) {
    int d;
    std::cout << "? " << i << ' ' << j << std::endl;
    std::cin >> d;
    return d;
  };

  int m = mex(x);
  if (m <= n) {
    int i = m;
    int j = m % n + 1;
    int d = query(i, j);
    if (d == 0) {
      std::cout << "! A" << std::endl;
    } else {
      std::cout << "! B" << std::endl;
    }
  } else {
    auto start = x.begin();
    auto end = x.end();
    int i = std::find(start, end, 1) - start + 1; 
    int j = std::find(start, end, n) - start + 1;

    int d1 = query(i, j);
    int d2 = query(j, i);
    if (d1 == d2 && d1 >= n - 1) {
      std::cout << "! B" << std::endl;
    } else {
      std::cout << "! A" << std::endl;
    }
  }
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
