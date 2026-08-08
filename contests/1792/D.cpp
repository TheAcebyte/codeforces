#include <array>
#include <iostream>
#include <vector>

constexpr int M = 10;

class trie {
private:
  using container = std::vector<int>;
  struct node {
    std::array<node*, M + 1> children;

    node() {
      children.fill(nullptr);
    }

    ~node() {
      for (auto child : children) {
        if (child != nullptr) {
          delete child;
        }
      }
    }
  };

  node* root = new node();

public:
  ~trie() {
    delete root;
  }

  void add(const container& p) {
    node* n = root;
    for (int x : p) {
      if (n->children[x] == nullptr) {
        n->children[x] = new node();
      }

      n = n->children[x];
    }
  }

  int get_longest_prefix(const container& p) {
    int size = 0;
    node* n = root;
    for (int x : p) {
      if (n->children[x] == nullptr) {
        break;
      }

      n = n->children[x];
      ++size;
    }

    return size;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  trie t;
  for (auto& p : a) {
    for (int& x : p) {
      std::cin >> x;
    }

    std::vector<int> q(m);
    for (int j = 0; j < m; ++j) {
      q[p[j] - 1] = j + 1;
    }

    t.add(q);
  }

  for (int i = 0; i < n; ++i) {
    const auto& p = a[i];
    int max_beauty = t.get_longest_prefix(p);
    std::cout << max_beauty << " \n"[i == n - 1];
  }
}

int main() {
#ifndef ONLINE_JUDGE
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
