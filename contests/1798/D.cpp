#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a;
  a.reserve(n);

  std::vector<int> positives;
  std::vector<int> negatives;

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x == 0) {
      a.push_back(x);
    } else if (x > 0) {
      positives.push_back(x);
    } else {
      negatives.push_back(x);
    }
  }

  if (positives.empty() && negatives.empty()) {
    std::cout << "NO\n";
    return;
  }

  int i = 0;
  int j = 0;
  int prefix_sum = 0;
  while (i < positives.size() || j < negatives.size()) {
    int x = prefix_sum >= 0 ? negatives[j++] : positives[i++];
    prefix_sum += x;
    a.push_back(x);
  }

  std::cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " \n"[i == n - 1];
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
