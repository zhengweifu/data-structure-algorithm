#ifndef __UTIL_COMMON_H__
#define __UTIL_COMMON_H__

#include <iostream>
namespace dsa { namespace util
{

template <typename T>
void printArray(T *data, size_t len)
{
	for (size_t i = 0; i < len; ++i)
	{
		if (i == 0)
		{
			cout << '[' << data[i];
		}
		else if (i == len - 1)
		{
			cout << ',' << data[i] << "]\n";
		}
		else
		{
			cout << ',' << data[i];
		}
	}
}

}}


#endif // __UTIL_COMMON_H__