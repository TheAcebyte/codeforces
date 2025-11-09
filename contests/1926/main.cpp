#include <iostream>

#define MAX 200001

constexpr int sumDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int lookup[MAX];
  lookup[0] = 0;
  for (int i = 0; i < MAX; ++i) {
    lookup[i] = lookup[i - 1] + sumDigits(i);
  }

  int T;
  std::cin >> T;
  while (T-- > 0) {
    int n;
    std::cin >> n;
    std::cout << lookup[n] << '\n';
  }

  return 0;
}
