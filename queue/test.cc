#include <assert.h>
#include <stdio.h>

#include "queue.h"

const int SIZE = 12;

void test() {
    queue<int> q0(SIZE);
    assert(q0.empty());
    q0.enqueue(1);
    q0.enqueue(2);
    assert(q0.size() == SIZE);
    assert(q0.count() == 2);
    assert(!q0.full());
    assert(1 == q0.dequeue());
    assert(2 == q0.dequeue());
    assert(q0.empty());

    queue<int> q1(2);
    q1.enqueue(2);
    q1.enqueue(1);
    assert(q1.full());
    assert(2 == q1.dequeue());
    q1.enqueue(3);
    assert(q1.full());
    assert(1 == q1.dequeue());
    assert(3 == q1.dequeue());
    assert(q1.empty());
}

int main() {
    test();
}
