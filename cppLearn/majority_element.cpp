#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
#include <math.h>

using std::deque;
using std::vector;

vector<int> merge_parts(deque<int> &a, deque<int> &b) {
  vector<int> c;
  while (!a.empty() && !b.empty()) {
	int A = a.front();
	int B = b.front();
	if (A <= B) {
		c.push_back(A);
		a.pop_front();
	}
	else {
		c.push_back(B);
		b.pop_front();
	}
  }
  if (!a.empty() && b.empty()) {
  	while (!a.empty()) {
		int A = a.front();
		a.pop_front();
		c.push_back(A);
	}
  }
  else if (!b.empty() && a.empty()) {	
  	while (!b.empty()) {
		int B = b.front();
		b.pop_front();
		c.push_back(B);
	}
  }
  else {
  	assert("this should not happen");
  }
  return c;
}

vector<int> merge_sort(const vector<int> &v) {
  int n = v.size();
  if (n == 1) {
  	return v;
  }
  int m = floor(n/2);
  vector<int> a(v.begin(), v.begin() + m);
  vector<int> b(v.begin() + m, v.end());
  vector<int> c = merge_sort(a);
  vector<int> d = merge_sort(b);
  deque<int> e (c.begin(), c.end());
  deque<int> f (d.begin(), d.end());
  vector<int> r = merge_parts(e, f);
  return r;
}

 
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return 0;
  if (left + 1 == right) return 1;

  vector<int> r = merge_sort(a);
  int count = 0;
  int n = a.size();
  for(int i=0; i < r.size() - 1; i++){
  	if (r[i] == r[i+1]) {
		count++;
	}
	else if (r[i] != r[i+1]) {
		count = 0;
	}
	if (count == n/2) {
		return 1;
	}
  }
  return 0;
}

 
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
