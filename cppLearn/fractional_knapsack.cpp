#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using std::map;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  std::map<double, int> r_index;
  for (int i = 0; i < values.size(); i++) {
	double r = (double) values[i] / weights[i];
	r_index[r] = i;
  }
  for (auto it = r_index.rbegin(); it != r_index.rend(); it++) {
	// can fit more than just this one item, or just this one
	if (capacity - weights[it->second] >= 0) {
		capacity = capacity - weights[it->second];
		value += (double) values[it->second];
	}
	// cannot fit whole item but can fit partial item
	else if (capacity > 0) {
		value += (double) capacity * it->first;
		capacity = 0;
	}
  }
  return value;

}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
