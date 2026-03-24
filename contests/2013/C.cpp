#include <deque>
#include <iostream>
#include <ostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::deque<T> &queue) {
  for (const auto &x : queue) {
    out << x;
  }

  return out;
}

void solve() {
  int n;
  std::cin >> n;

  auto query = [](const std::deque<char> &s) {
    bool valid;
    std::cout << "? " << s << std::endl;
    std::cin >> valid;
    return valid;
  };

  auto submit = [](const std::deque<char> &s) {
    std::cout << "! " << s << std::endl;
  };

  std::deque<char> s;
  while (s.size() < n) {
    s.push_back('0');
    if (query(s)) {
      continue;
    }

    s.back() = '1';
    if (query(s)) {
      continue;
    }

    s.pop_back();
    break;
  }

  while (s.size() < n) {
    s.push_front('0');
    if (!query(s)) {
      s.front() = '1';
    }
  }

  submit(s);
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
