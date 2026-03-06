#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(m);
  for (int &x : b) {
    std::cin >> x;
  }

  std::vector<int> c(m);
  for (int &x : c) {
    std::cin >> x;
  }

  std::multiset<int> swords;
  for (int x : a) {
    swords.insert(x);
  }

  std::vector<int> yielding;
  std::vector<int> non_yielding;
  for (int i = 0; i < m; ++i) {
    if (c[i] > 0) {
      yielding.push_back(i);
    } else {
      non_yielding.push_back(i);
    }
  }

  auto cmp = [&](int i, int j) { return b[i] < b[j]; };
  std::sort(yielding.begin(), yielding.end(), cmp);
  std::sort(non_yielding.rbegin(), non_yielding.rend(), cmp);

  int result = 0;
  for (int i : yielding) {
    auto it = swords.lower_bound(b[i]);
    if (it == swords.end()) {
      break;
    }

    ++result;
    if (c[i] > *it) {
      swords.erase(it);
      swords.insert(c[i]);
    }
  }

  for (int i : non_yielding) {
    auto it = swords.lower_bound(b[i]);
    if (it == swords.end()) {
      continue;
    }

    ++result;
    swords.erase(it);
  }

  std::cout << result << '\n';
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
