#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::pair<int, int> count_balanced_subtrees(const std::vector<int> &p,
                                            const std::string &s,
                                            int node = 0) {
  int n = p.size();
  int count = 0;
  int balance = s[node] == 'B' ? -1 : 1;
  for (int i = 0; i < n; ++i) {
    if (p[i] == node) {
      auto pair = count_balanced_subtrees(p, s, i);
      count += pair.first;
      balance += pair.second;
    }
  }

  if (balance == 0) {
    ++count;
  }

  return {count, balance};
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  p[0] = -1;
  for (int i = 1; i < n; ++i) {
    std::cin >> p[i];
    --p[i];
  }

  std::string s;
  std::cin >> s;

  int result = count_balanced_subtrees(p, s).first;
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
