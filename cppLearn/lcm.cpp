#include <iostream>

long long gcd(int a, int b) {
	int c = 0;
	while (b > 0) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

long long lcm(int a, int b) {
	long long g = gcd(a, b);
	long long l = (long long) a * b / g;
	return l;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  long long l = lcm(a, b);
  std::cout << l << std::endl;
  //std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}

