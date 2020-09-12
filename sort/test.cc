#include <new>

#include "sort.h"

/* test cases

    create random length array and see if sorted
*/
void testSort() {
    int len = 10;
    int* arr = new (std::nothrow) int[len];
    arr[0] = 65;
    arr[1] = 22;
    arr[2] = 73;
    arr[3] = 29;
    arr[4] = 22;
    arr[5] = 102;
    arr[6] = 135;
    arr[7] = 910293;
    arr[8] = -102;
    arr[9] = 0;
    sort<int> sorted(arr, len);
    int* narr = sorted.Sorted();
    for (int i = 1; i < len; i++) {
        assert(narr[i] >= narr[i-1]);
    }
}

int main() {
    testSort();
}
