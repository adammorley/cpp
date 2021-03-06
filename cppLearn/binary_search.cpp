#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size() - 1;
  while (true) {
  	int midpoint = (int) floor( (right-left) /2) + left;
	if (a[midpoint] == x) {
		return midpoint;
	}
	else if (right == midpoint) {
		return -1;
	}
	else if (x < a[midpoint]) {
		right = midpoint;
	}
	else if (x > a[midpoint]) {
		left = midpoint + 1;
	}
	else {
		std::cout << "broke" << '\n' << std::endl;
	}
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
