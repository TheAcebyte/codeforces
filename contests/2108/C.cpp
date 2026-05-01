#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) { std::cin >> x; }

  std::vector<bool> pressed(n);
  std::vector<bool> pending(n);

  auto cmp_indices = [&](int i, int j) { return a[i] > a[j]; };
  std::vector<int> indices(n);
  std::iota(indices.begin(), indices.end(), 0);
  std::sort(indices.begin(), indices.end(), cmp_indices);

  auto cmp_reachable = [&](int i, int j) { return a[i] < a[j]; };
  std::priority_queue<int, std::vector<int>, decltype(cmp_reachable)> reachable(
      cmp_reachable);

  auto press_button = [&](int i) {
    if (pressed[i]) return;
    pressed[i] = true;

    if (i > 0 && !pressed[i - 1] && !pending[i - 1]) {
      reachable.push(i - 1);
      pending[i - 1] = true;
    }

    if (i < n - 1 && !pressed[i + 1] && !pending[i + 1]) {
      reachable.push(i + 1);
      pending[i + 1] = true;
    }
  };

  int k = 0;
  int clones = 0;
  while (k < n) {
    int i = indices[k];
    if (pressed[i]) {
      ++k;
      continue;
    }

    bool is_reachable = false;
    if (!reachable.empty()) {
      int j = reachable.top();
      if (a[i] == a[j]) {
        reachable.pop();
        press_button(j);
        is_reachable = true;
      }
    }

    if (!is_reachable) {
      press_button(i);
      ++clones;
    }
  }

  std::cout << clones << '\n';
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
