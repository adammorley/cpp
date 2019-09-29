#include <assert.h>
#include <stdio.h>

#include "stack.h"

const int SIZE = 12;

void test() {
    stack<int> s(SIZE);
    assert(s.empty());
    s.Push(1);
    s.Push(2);
    assert(s.size() == SIZE);
    assert(s.count() == 2);
    assert(!s.full());
    assert(2 == s.Pop());
    assert(1 == s.Pop());
    assert(s.empty());

    stack<int> t(2);
    t.Push(1);
    t.Push(2);
    assert(t.full());
}

int main() {
    test();
}
