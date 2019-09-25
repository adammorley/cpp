#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

void test() {
    linkedList<int> ll(1);
    ll.add(2);
    ll.add(1);
    assert(1 == ll.del(1));

    const unsigned short l = 8;
    unsigned char* blah = (unsigned char*) malloc(sizeof(unsigned char)*l);
    char boo[l] = "abcdefg";
    memcpy(blah, &boo, l);
    linkedList<unsigned char*> lll(blah);
}

int main() {
    test();
}
