#include <assert.h>
#include <new>

template <class T>
sort<T>::sort(T* values, unsigned int len) {
    this->sorted_ = mergeSort(values, len);
    this->count_ = len;
}

template <class T>
T* sort<T>::mergeSort(T* ptr, unsigned int len) {
    if (len==1 || len==0) return ptr;
    int fL = len/2, bL = len/2; // even case
    if (len%2 != 0) { // not even
        fL = len/2 + 1;
        bL = len/2;
    }
    T* front = new (std::nothrow) T[fL];
    assert(front != nullptr);
    T* back = new (std::nothrow) T[bL];
    assert(back != nullptr);
    int i;
    for (i=0; i<fL; i++) {
        front[i] = ptr[i];
    }
    int j=0;
    for (i=fL; i<len; i++) {
        back[j] = ptr[i];
        j++;
    }
    delete[] ptr;
    return merge(mergeSort(front, fL), mergeSort(back, bL), fL, bL);
}

template <class T>
T* sort<T>::merge(T* ptr0, T* ptr1, unsigned int ptr0L, unsigned int ptr1L) {
    int size = ptr0L + ptr1L;
    T* ret = new (std::nothrow) T[size];
    assert(ret != nullptr);
    int i = 0, j = 0, k = 0;
    for (i=0; i<size; i++) {
        if (j >= ptr0L) { // reached end of first array, just keep pulling from second
            ret[i] = ptr1[k];
            k++;
        } else if (k >= ptr1L) { // "" first
            ret[i] = ptr0[j];
            j++;
        } else if (ptr0[j] <= ptr1[k]) { // first lower
            ret[i] = ptr0[j];
            j++;
        } else if (ptr0[j] > ptr1[k]) { // second lower
            ret[i] = ptr1[k];
            k++;
        } else assert(false);
    }
    delete[] ptr0;
    delete[] ptr1;
    return ret;
}
