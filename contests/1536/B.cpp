#include <cstddef>
#include <deque>
#include <iostream>
#include <string>

class ordered_string {
private:
  std::deque<char> data;

public:
  ordered_string() : data{'a'} {}

  std::size_t size() const { return data.size(); }
  std::size_t length() const { return data.size(); }
  const char &operator[](std::size_t index) const { return data[index]; }
  std::deque<char>::const_iterator begin() const { return data.begin(); }
  std::deque<char>::const_iterator end() const { return data.end(); }

  ordered_string &operator++() {
    std::ptrdiff_t i = data.size() - 1;
    while (i >= 0) {
      ++data[i];
      if (data[i] <= 'z') {
        break;
      }

      data[i--] = 'a';
    }

    if (i < 0) {
      data.push_front('a');
    }

    return *this;
  }

  explicit operator std::string() const {
    std::size_t n = data.size();
    std::string s;
    s.reserve(n);

    for (char c : data) {
      s.push_back(c);
    }

    return s;
  }
};

bool has_substring(const std::string &s, const ordered_string &t) {
  int n = s.length();
  int m = t.length();
  for (int i = 0; i < n - m + 1; ++i) {
    int j = 0;
    while (j < m && s[i + j] == t[j]) {
      ++j;
    }

    if (j >= m) {
      return true;
    }
  }

  return false;
}

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  ordered_string t;
  while (has_substring(s, t)) {
    ++t;
  }

  std::cout << static_cast<std::string>(t) << '\n';
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
