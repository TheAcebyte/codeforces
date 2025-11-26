#include <iostream>
#include <string>

struct Path {
  int effective;
  int redundant;
  bool taken;
  char first;
  char rest;
};

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int north = 0;
  int south = 0;
  int east = 0;
  int west = 0;
  for (char c : s) {
    if (c == 'N') {
      ++north;
    } else if (c == 'S') {
      ++south;
    } else if (c == 'E') {
      ++east;
    } else {
      ++west;
    }
  }

  if (std::abs(north - south) & 1 || std::abs(east - west) & 1) {
    std::cout << "NO\n";
    return;
  }

  Path northPath{
      std::max((north - south) / 2, 0), std::min(north, south), false, 'R', 'H',
  };

  Path southPath{
      std::max((south - north) / 2, 0), std::min(north, south), false, 'R', 'H',
  };

  Path eastPath{
      std::max((east - west) / 2, 0), std::min(east, west), false, 'H', 'R',
  };

  Path westPath{
      std::max((west - east) / 2, 0), std::min(east, west), false, 'H', 'R',
  };

  int effective = northPath.effective + southPath.effective +
                  eastPath.effective + westPath.effective;
  int redundant = northPath.redundant + southPath.redundant +
                  eastPath.redundant + westPath.redundant;

  if (effective == 0 && redundant <= 2) {
    std::cout << "NO\n";
    return;
  }

  for (char c : s) {
    Path *wrapper = nullptr;
    if (c == 'N') {
      wrapper = &northPath;
    } else if (c == 'S') {
      wrapper = &southPath;
    } else if (c == 'E') {
      wrapper = &eastPath;
    } else {
      wrapper = &westPath;
    }

    Path &path = *wrapper;
    if (path.redundant) {
      --path.redundant;
      if (!path.taken) {
        std::cout << path.first;
        path.taken = true;
      } else {
        std::cout << path.rest;
      }
    } else if (path.effective) {
      --path.effective;
      std::cout << 'R';
    } else {
      std::cout << 'H';
    }
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
