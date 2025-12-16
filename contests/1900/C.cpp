#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
  char direction;
  int left;
  int right;
};

int helper(const std::vector<TreeNode> &nodes, int index) {
  auto node = nodes[index];
  if (node.left == 0 && node.right == 0) {
    return 0;
  }

  if (node.right == 0) {
    return helper(nodes, node.left) + (node.direction != 'L');
  }

  if (node.left == 0) {
    return helper(nodes, node.right) + (node.direction != 'R');
  }

  int left = helper(nodes, node.left);
  int right = helper(nodes, node.right);
  if ((left <= right && node.direction == 'L') ||
      (left >= right && node.direction == 'R')) {
    return std::min(left, right);
  } else {
    return std::min(left, right) + 1;
  }
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<TreeNode> nodes(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> nodes[i].direction;
  }

  for (int i = 1; i <= n; ++i) {
    std::cin >> nodes[i].left;
    std::cin >> nodes[i].right;
  }

  int result = helper(nodes, 1);
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
