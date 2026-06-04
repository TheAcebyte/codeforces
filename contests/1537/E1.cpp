#include <algorithm>
#include <iostream>
#include <string>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  auto reach_k = [&]() -> std::string {
    std::string t(s);
    while ((int)t.length() < k) {
      t += t;
    }

    while ((int)t.length() > k) {
      t.pop_back();
    }

    return t;
  };

  std::string min_t;
  bool set = false;
  while (!s.empty()) {
    auto t = reach_k();
    if (!set || std::lexicographical_compare(t.begin(), t.end(), min_t.begin(),
                                             min_t.end())) {
      min_t = std::move(t);
      set = true;
    }

    s.pop_back();
  }

  std::cout << min_t << '\n';
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
