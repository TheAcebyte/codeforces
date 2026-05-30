#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

void setmin(int& x, int y) { x = std::min(x, y); }
void setmax(int& x, int y) { x = std::max(x, y); }

constexpr int N = 1e3;
constexpr int INF = 1e9;
std::array<int, N + 1> ops;

void precompute_ops() {
  ops.fill(INF);
  ops[0] = ops[1] = 0;
  for (int x = 1; x <= N; ++x) {
    for (int d = 1; d <= x; ++d) {
      int y = x + x / d;
      if (y <= N) {
        setmin(ops[y], ops[x] + 1);
      }
    }
  }
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  int max_k = *std::max_element(ops.begin(), ops.end()) * n;
  setmin(k, max_k);

  std::vector<int> b(n);
  for (int& x : b) { std::cin >> x; }

  std::vector<int> c(n);
  for (int& x : c) { std::cin >> x; }

  std::vector<int> dp(k + 1);
  for (int i = 0; i < n; ++i) {
    int y = b[i];
    for (int j = k; j >= ops[y]; --j) {
      setmax(dp[j], dp[j - ops[y]] + c[i]);
    }
  }

  int max_coins = dp[k];
  std::cout << max_coins << '\n';
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  precompute_ops();

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}

