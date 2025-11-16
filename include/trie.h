#pragma once

#include <cassert>
#include <memory>
#include <stdexcept>
#include <string_view>

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
