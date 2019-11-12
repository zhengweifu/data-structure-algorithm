// get parent = (i - 1) / 2
// get left child ( lc = 2 * i + 1 ), right child ( rc = 2 * i + 2 )

#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#include "util/common.h"

#include <stdio.h>
#include <cstring>

using namespace dsa;

namespace alg
{
namespace sort
{

template <typename T>
void heapify(T *data, size_t n, size_t i)
{
    if (i >= n - 1)
    {
        return;
    }
    size_t c1 = 2 * i + 1;
    size_t c2 = 2 * i + 2;
    size_t max = i;
    if (c1 < n && data[c1] > data[i])
    {
        max = c1;
    }
    if (c2 < n && data[c2] > data[max])
    {
        max = c2;
    }

    if (max != i)
    {
        util::swap(data, i, max);
        heapify(data, n, max);
    }
}

template <typename T>
void buildHeap(T *data, size_t n)
{
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        heapify(data, n, i);
    }
}

template <typename T>
void heapSort(T *data, size_t n)
{
    buildHeap(data, n);
    for (size_t i = n - 1; i > 0; --i)
    {
        util::swap(data, i, 0);
        heapify(data, i, 0);
    }
}

} // namespace sort
} // namespace alg

#endif // __HEAP_SORT_H__