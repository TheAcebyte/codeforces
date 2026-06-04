#include <array>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void setmax(T& x, const T& y) { if (y > x) x = y; }

template<typename T>
T query(const std::vector<T>& a, T l, T r) {
  int s = a[r];
  if (l > 0) s -= a[l - 1];
  return s;
}

constexpr int P = 6;
std::array<std::string, P> permutations{{
  "abc",
  "acb",
  "bac",
  "bca",
  "cab",
  "cba",
}};

void solve() {
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;

  std::array<std::vector<int>, P> p;
  p.fill(std::vector<int>(n));
  for (int j = 0; j < P; ++j) {
    p[j][0] = s[0] == permutations[j][0];
    int length = permutations[j].length();
    for (int i = 1; i < n; ++i) {
      int k = i % length;
      p[j][i] = p[j][i - 1] + (s[i] == permutations[j][k]);
    }
  }

  while (m-- > 0) {
    int l, r;
    std::cin >> l >> r;
    --l; --r;

    int max_similarity = 0;
    for (int j = 0; j < P; ++j) {
      int similarity = query(p[j], l, r);
      setmax(max_similarity, similarity);
    }

    int min_cost = r - l + 1 - max_similarity;
    std::cout << min_cost << '\n';
  }
}

int main() {
#ifndef ONLINE_JUDGE 
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
