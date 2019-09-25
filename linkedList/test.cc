#include <assert.h>
#include <stdio.h>

#include "linkedList.h"

void test() {
    linkedList<int> ll(1);
    ll.add(2);
    ll.add(1);
    assert(1 == ll.del(1));
}

int main() {
    test();
}
