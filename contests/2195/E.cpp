#include <cstdint>
#include <iostream>
#include <vector>

#define M 1000000007

using i64 = std::int64_t;

struct binary_node {
  int left = 0;
  int right = 0;

  bool is_leaf() const { return left == 0 && right == 0; }
};

using binary_tree = std::vector<binary_node>;

i64 calculate_time_to_parent(const binary_tree &tree, int u,
                             std::vector<i64> &dp) {
  if (dp[u] > 0) {
    return dp[u];
  }

  int l = tree[u].left;
  int r = tree[u].right;
  i64 left_time = calculate_time_to_parent(tree, l, dp);
  i64 right_time = calculate_time_to_parent(tree, r, dp);

  i64 total_time = (3 + left_time + right_time) % M;
  dp[u] = total_time;
  return total_time;
}

void calculate_total_time(const binary_tree &tree, int u, int p,
                          std::vector<i64> &dp) {
  dp[u] = (dp[u] + dp[p]) % M;
  if (tree[u].is_leaf()) {
    return;
  }

  int l = tree[u].left;
  int r = tree[u].right;
  calculate_total_time(tree, l, u, dp);
  calculate_total_time(tree, r, u, dp);
}

void solve() {
  int n;
  std::cin >> n;

  binary_tree tree(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> tree[i].left >> tree[i].right;
  }

  std::vector<i64> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (tree[i].is_leaf()) {
      dp[i] = 1;
    }
  }

  calculate_time_to_parent(tree, 1, dp);
  calculate_total_time(tree, 1, 0, dp);

  const char *separator = "";
  for (int k = 1; k <= n; ++k) {
    std::cout << separator << dp[k];
    separator = " ";
  }
  std::cout << '\n';
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
