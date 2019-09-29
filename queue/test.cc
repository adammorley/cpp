#include <assert.h>
#include <stdio.h>

#include "queue.h"

const int SIZE = 12;

void test() {
    queue<int> q0(SIZE);
    assert(q0.empty());
    q0.Enqueue(1);
    q0.Enqueue(2);
    assert(q0.size() == SIZE);
    assert(q0.count() == 2);
    assert(!q0.full());
    assert(1 == q0.Dequeue());
    assert(2 == q0.Dequeue());
    assert(q0.empty());

    queue<int> q1(2);
    q1.Enqueue(2);
    q1.Enqueue(1);
    assert(q1.full());
    assert(2 == q1.Dequeue());
    q1.Enqueue(3);
    assert(q1.full());
    assert(1 == q1.Dequeue());
    assert(3 == q1.Dequeue());
    assert(q1.empty());
}

int main() {
    test();
}
