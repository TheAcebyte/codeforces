#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

std::string format_card(char suit, int rank) {
  return std::to_string(rank) + suit;
}

void solve() {
  int n;
  char trump_suit;
  std::cin >> n >> trump_suit;

  std::map<char, std::vector<int>> suits;
  for (int i = 0; i < 2 * n; ++i) {
    int rank;
    char suit;
    std::cin >> rank >> suit;
    suits[suit].push_back(rank);
  }

  for (auto &[suit, ranks] : suits) {
    std::sort(ranks.begin(), ranks.end());
  }

  std::vector<std::pair<std::string, std::string>> rounds;
  rounds.reserve(n);

  const auto &trump_ranks = suits[trump_suit];
  int trump_size = trump_ranks.size();
  int trump_index = 0;
  for (auto [suit, ranks] : suits) {
    if (suit == trump_suit) {
      continue;
    }

    int m = ranks.size();
    for (int i = 0; i < m - 1; i += 2) {
      auto first_card = format_card(suit, ranks[i]);
      auto second_card = format_card(suit, ranks[i + 1]);
      rounds.emplace_back(first_card, second_card);
    }

    if (m & 1) {
      if (trump_index >= trump_size) {
        std::cout << "IMPOSSIBLE\n";
        return;
      }

      auto first_card = format_card(suit, ranks[m - 1]);
      auto second_card = format_card(trump_suit, trump_ranks[trump_index]);
      rounds.emplace_back(first_card, second_card);
      ++trump_index;
    }
  }

  while (trump_index < trump_size - 1) {
    auto first_card = format_card(trump_suit, trump_ranks[trump_index]);
    auto second_card = format_card(trump_suit, trump_ranks[trump_index + 1]);
    rounds.emplace_back(first_card, second_card);
    trump_index += 2;
  }

  if (trump_index < trump_size) {
    std::cout << "IMPOSSIBLE\n";
    return;
  }

  for (auto round : rounds) {
    std::cout << round.first << ' ' << round.second << '\n';
  }
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
