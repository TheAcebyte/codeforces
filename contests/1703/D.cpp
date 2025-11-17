#include <cassert>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string_view>
#include <vector>

class TrieNode {
private:
  bool word;
  std::unique_ptr<TrieNode> children[26];

public:
  TrieNode() : word(false) {
    for (auto &child : children) {
      child = nullptr;
    }
  }

  friend class Trie;
};

class Trie {
private:
  std::unique_ptr<TrieNode> root;

  int index(char c) {
    if (c < 'a' || c > 'z') {
      throw std::runtime_error("Character must be in a-z range.");
    }

    return c - 'a';
  }

public:
  Trie() : root(std::make_unique<TrieNode>()) {}

  void insert(std::string_view word) {
    TrieNode *node = root.get();

    for (char letter : word) {
      int i = index(letter);
      if (node->children[i] == nullptr) {
        node->children[i] = std::make_unique<TrieNode>();
      }

      node = node->children[i].get();
    }

    node->word = true;
  }

  bool exists(std::string_view word) {
    TrieNode *node = root.get();

    for (char letter : word) {
      int i = index(letter);
      if (node->children[i] == nullptr) {
        return false;
      }

      node = node->children[i].get();
    }

    return node->word;
  }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> a(n);
  Trie trie;
  for (auto &s : a) {
    std::cin >> s;
    trie.insert(s);
  }

  for (auto &s : a) {
    int m = s.length();
    bool found = false;

    for (int i = 1; i < m; ++i) {
      std::string_view prefix(s.data(), i);
      std::string_view suffix(s.data() + i, m - i);
      if (trie.exists(prefix) && trie.exists(suffix)) {
        found = true;
        break;
      }
    }

    std::cout << found;
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
