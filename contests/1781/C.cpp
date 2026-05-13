#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::array<std::pair<int, char>, 26>
get_sorted_letter_frequency(const std::string &s) {
  std::array<std::pair<int, char>, 26> count;
  for (char c = 'a'; c <= 'z'; ++c) {
    int i = c - 'a';
    count[i].first = 0;
    count[i].second = c;
  }

  for (char c : s) {
    int i = c - 'a';
    ++count[i].first;
  }

  std::sort(count.begin(), count.end());
  return count;
}

std::array<std::vector<int>, 26> get_letter_positions(const std::string &s) {
  int n = s.length();
  std::array<std::vector<int>, 26> positions;
  positions.fill({});
  for (int i = 0; i < n; ++i) {
    int j = s[i] - 'a';
    positions[j].push_back(i);
  }

  return positions;
}

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  auto initial_frequency = get_sorted_letter_frequency(s);
  auto initial_positions = get_letter_positions(s);
  int min_changes = n + 1;
  std::string min_t;

  int min_d = (n + 25) / 26;
  for (int d = min_d; d <= n; ++d) {
    if (n % d != 0) {
      continue;
    }

    auto positions = initial_positions;
    auto frequency = initial_frequency;
    int changes = 0;
    std::string t = s;

    int i = 0;
    while (i < 26 && frequency[i].first < d) {
      ++i;
    }
    --i;

    int j = 25;
    while (i >= 0 && j >= 0 && frequency[j].first > d) {
      ++changes;
      --frequency[j].first;
      ++frequency[i].first;
      char from_c = frequency[j].second;
      char to_c = frequency[i].second;
      int p = positions[from_c - 'a'].back();
      positions[from_c - 'a'].pop_back();
      t[p] = to_c;
      if (frequency[j].first == d) --j;
      if (frequency[i].first == d) --i;
    }

    int k = 0;
    while (k < i) {
      if (frequency[k].first == 0) {
        ++k;
        continue;
      }

      if (frequency[i].first == d) {
        --i;
        continue;
      }

      ++changes;
      --frequency[k].first;
      ++frequency[i].first;
      char from_c = frequency[k].second;
      char to_c = frequency[i].second;
      int p = positions[from_c - 'a'].back();
      positions[from_c - 'a'].pop_back();
      t[p] = to_c;
    }

    if (changes < min_changes) {
      min_changes = changes;
      min_t = std::move(t);
    }
  }

  std::cout << min_changes << '\n';
  std::cout << min_t << '\n';
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
