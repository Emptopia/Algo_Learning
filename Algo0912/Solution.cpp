#include "Solution.h"
#define __builtin_popcount __popcnt 
#define __builtin_popcountl __popcnt

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

int  Solution::hammingDistance(int x, int y)
{
	//原理：
	// 两个整数之间的汉明距离是对应位置上数字不同的位数。使用异或运算，记为⊕，当且仅当输入位不同时输出为 1。
	
	//方法1：
	//return __builtin_popcount(x ^ y);						//力扣版本，计数异或中出现1的次数
	//return __popcnt(x ^ y);										//当前版本
	
	
	//方法2：
	int s = x ^ y, ret = 0;
	while (s) 
	{
		ret += s & 1;					//当s&1=1(s的最末位=1)，ret+1
		s >>= 1;							//s右移一位，这样，s最末位被舍去，直到s=0
	}
	return ret;



}