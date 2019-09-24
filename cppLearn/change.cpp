#include <iostream>
#include <map>

using std::map;

int get_change(int money) {
  map<int, int> MinNumCoins;
  MinNumCoins[0] = 0;
  for (int m = 1; m <= money; m++) {
    MinNumCoins[m] = 1874919424;
    for (int i: {1, 5, 10, 20, 25}) {
        if (m >= i) {
            int NumCoins = MinNumCoins[m-i] + 1;
            if (NumCoins < MinNumCoins[m]) {
                MinNumCoins[m] = NumCoins;
            }
        }
    }
  }
  return MinNumCoins[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
