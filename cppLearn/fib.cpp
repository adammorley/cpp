#include <iostream>
#include <vector>

int main() {
  std::vector<long long> fib;
  fib.push_back(0);
  fib.push_back(1);
  long long a;
  std::cin >> a;
  long long cnt = 2;
  while (cnt <= a) {
	long long num = fib[cnt-1] + fib[cnt-2];
	fib.push_back(num);
	cnt++;
  }
  std::cout << fib[a] << std::endl;
  //std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}

