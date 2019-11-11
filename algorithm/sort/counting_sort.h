#ifndef __COUNTING_SORT_H__
#define __COUNTING_SORT_H__

#include "util/common.h"

#include <stdio.h>
#include <cstring>

namespace alg 
{
	namespace sort
	{
		void countingSort(int *data, int len, int max, int min)
		{
			const int n = max - min + 1;
			int *bucket = new int[n]();
			int *dataBak = new int[len]();
			memcpy(dataBak, data, len * sizeof(int));

			//util::printArray(dataBak, len);

			for (int i = 0; i < len; ++i)
			{
				bucket[data[i] - min] += 1;
			}

			//util::printArray(bucket, n);

			for (int i = 1; i < n; ++i)
			{
				bucket[i] += bucket[i - 1];
			}

			//util::printArray(bucket, n);

			for (int i = len - 1; i >= 0; --i)
			{
				int &countor = bucket[dataBak[i] - min];
				data[-1 + countor--] = dataBak[i];
			}

			delete[] bucket;
			delete[] dataBak;
		}
	}
}


#endif // __COUNTING_SORT_H__