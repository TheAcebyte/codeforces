#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::string hits, sounds;
    std::cin >> hits >> sounds;

    auto hit = hits.begin();
    auto sound = sounds.begin();

    if (*hit != *sound) {
      std::cout << "NO" << '\n';
      continue;
    }

    char previous = *hit;
    int repetitions = 1;
    ++hit;
    ++sound;

    while (sound != sounds.end()) {
      if (*hit == *sound) {
        if (*hit == previous) {
          ++repetitions;
        } else {
          repetitions = 1;
        }

        previous = *hit;
        ++hit;
        ++sound;
      } else {
        while (sound != sounds.end() && repetitions > 0 && *sound == previous) {
          --repetitions;
          ++sound;
        }

        if ((hit == hits.end() && sound != sounds.end()) ||
            (hit != hits.end() && *hit != *sound)) {
          break;
        }
      }
    }

    std::cout << (hit == hits.end() && sound == sounds.end() ? "YES" : "NO")
              << '\n';
  }

  return 0;
}
