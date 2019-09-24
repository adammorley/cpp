#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using std::map;
using std::vector;

vector<int> opcount(int number) {
  map<int, vector<int>> path;
  int NumOps;
  int t;
  path[1] = {};
  for (int n = 2; n <= number; n++) {
    if (n % 3 == 0) {
        t = n /3;
        path[n] = path[t];
        path[n].push_back(t);
    }
    if (n % 2 == 0) {
        t = n /2;
        if (path.find(n) == path.end()) {
            //not found
            path[n] = path[t];
            path[n].push_back(t);
        }
        else if (path[t].size() + 1 < path[n].size()) {
                path[n] = path[t];
                path[n].push_back(t);
        }
    }
    if (path.find(n) == path.end()) {
        //not found
        path[n] = path[n-1];
        path[n].push_back(n-1);
    }
    else if (path[n-1].size() + 1 < path[n].size()) {
        path[n] = path[n-1];
        path[n].push_back(n-1);
    }
  }
  path[number].push_back(number);
  return path[number];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> x = opcount(n);
  std::cout << x.size() - 1 << std::endl;
  for (size_t i = 0; i < x.size(); ++i) {
    std::cout << x[i] << " ";
  }
}
