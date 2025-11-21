#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> indices(n);
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }

  auto cmp = [&a](int i, int j) { return a[i] > a[j]; };
  std::sort(indices.begin(), indices.end(), cmp);

  std::vector<int> p(n), q(n);
  std::vector<bool> pTaken(n + 1), qTaken(n + 1);
  pTaken[0] = qTaken[0] = true;
  int pn = n, qn = n;

  for (int i = 0; i < n; ++i) {
    int j = indices[i];
    int x = a[j];
    if (!pTaken[x]) {
      p[j] = x;
      pTaken[x] = true;
    } else if (!qTaken[x]) {
      q[j] = x;
      qTaken[x] = true;
    } else {
      std::cout << "NO\n";
      return;
    }
  }

  for (int i = 0; i < n; ++i) {
    int j = indices[i];
    if (q[j]) {
      continue;
    }

    while (qn > 0 && (qTaken[qn] || qn > p[j])) {
      --qn;
    }

    if (qn <= 0) {
      std::cout << "NO\n";
      return;
    }

    q[j] = qn;
    qTaken[qn] = true;
  }

  for (int i = 0; i < n; ++i) {
    int j = indices[i];
    if (p[j]) {
      continue;
    }

    while (pn > 0 && (pTaken[pn] || pn > q[j])) {
      --pn;
    }

    if (pn <= 0) {
      std::cout << "NO\n";
      return;
    }

    p[j] = pn;
    pTaken[pn] = true;
  }

  std::cout << "YES\n";

  const char *separator = "";
  for (int x : p) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';

  separator = "";
  for (int x : q) {
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
