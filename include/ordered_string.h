#pragma once

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
