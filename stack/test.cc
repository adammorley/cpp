#include <assert.h>
#include <stdio.h>

#include "stack.h"

void test() {
    stack<int> s1(17);
    s1.push(1);
    s1.push(2);
    assert(!s1.full());
    assert(2 == s1.pop());
}

int main() {
    test();
}
