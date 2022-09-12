#include "Solution.h"

int Solution::hammingWeight(uint32_t n)
{
	//n & (n−1)，其运算结果恰为把 nn 的二进制位中的最低位的 11 变为 00 之后的结果。
	//如 6 & (6 - 1) = 4,   6 = 110, 5 = 101, 4 = 100
	int res = 0;
	while (n)
	{
		n = n & (n - 1);
		res++;
	}
	//and运算(按位与)通常用于二进制的取位操作，例如一个数 and 1的结果就是取二进制的最末位。

	return res;
}