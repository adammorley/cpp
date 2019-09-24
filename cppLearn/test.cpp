#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


int main() {
  std::vector<int> values = {100, 50, 33};
  std::vector<int> weights = {10, 25, 10};
  std::map<double, int> r_index;
  for (int i = 0; i < values.size(); i++) {
	double r = (double) values[i] / weights[i];
	r_index[r] = i;
  }

  for (auto it = r_index.rbegin(); it != r_index.rend(); it++) {
  	std::cout << it->first << " " << it->second << '\n' << std::endl;
  }
  return 0;
}
