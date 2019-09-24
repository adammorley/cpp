#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>

using std::map;
using std::pair;
using std::set;
using std::vector;

int optimal_weight(int W, const vector<int> &weights) {
    map<int, map<int, int>> w_a;
    map<int, int> w_t;
    w_a[0] = {};
    for (int m = 1; m <= W; m++) {
        for (int w: weights) {
            if (m==w) {
                w_a[m][w] = 1;
                w_t[m] = w;
            }
            else if (w_t[m-1] + w > w_t[m] && w_a[m-1][w] == 1) {
                    w_a[m] = w_a[m-1];
                    w_t[m] = w_t[m-1];
                    w_a[m][w] = 1;
                    w_t[m] += w;
            }
        }
    }
    for (auto m: w_a) {
        for (auto w: w_a[m]) {
            std::cout << "m " << m << " w " << w << std::endl;
        }
    }
    return 0;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
