#include <assert.h>
#include <stdio.h>

#include "stack.h"

const int SIZE = 12;

void test() {
    stack<int> s(SIZE);
    assert(s.empty());
    s.push(1);
    s.push(2);
    assert(s.size() == SIZE);
    assert(s.count() == 2);
    assert(!s.full());
    assert(2 == s.pop());
    assert(1 == s.pop());
    assert(s.empty());

    stack<int> t(2);
    t.push(1);
    t.push(2);
    assert(t.full());
}

int main() {
    test();
}
