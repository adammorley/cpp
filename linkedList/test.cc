#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

void test() {
    linkedList<int> ll(1);
    ll.Add(2);
    ll.Add(1);
    assert(1 == ll.Delete(1));

    const unsigned short l = 8;
    unsigned char* blah = (unsigned char*) malloc(sizeof(unsigned char)*l);
    char boo[l] = "abcdefg";
    memcpy(blah, &boo, l);
    linkedList<unsigned char*> lll(blah);
}

int main() {
    test();
}
