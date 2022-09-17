#include "Solution.h"
#define __builtin_popcount __popcnt 
#define __builtin_popcountl __popcnt

void Solution::printVV(vector<vector<int>>v)
{
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator itt = it->begin(); itt != it->end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
}

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

uint32_t Solution::reverseBits(uint32_t n)
{
	//return Integer.reverse(n);				未知的库

	//		(n & 1) 返回n的最末位，<< (31 - i) 左移 31 - i 位，即可逆序返回到res对应的高位，
	//		和之前结果进行一次或运算 |=，整合了每一位的结果
	uint32_t res = 0;
	for (int i = 0; i < 32; i++)
	{
		res |= (n & 1) << (31 - i);
		n >>= 1;

		//易于理解
		//res = res << 1;				//res左移
		//res = res | (n & 1);		//res取n末位
		//n = n >> 1;					//n右移
	}
	return res;
}

vector<vector<int>> Solution::generate(int numRows)
{
	vector<vector<int>>res(numRows);
	res[0] = { 1 };
	for (int i = 1; i < numRows; i++)
	{
		res[i] = vector<int>(i+1);
		res[i][0] = 1;
		res[i][i] = 1;
		for (int a = 1, b = i-1; a <= b; a++, b--)
		{
			res[i][a] = res[i - 1][a - 1] + res[i - 1][a];
			res[i][b] = res[i][a];
		}
	}
	return res;
}

bool Solution::isValid(string s)
{
	//()[]{}
	stack<char>temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' or s[i] == '[' or s[i] == '{')
		{
			temp.push(s[i]);
		}
		else
		{
			if (temp.empty())
				return false;
			if (s[i] == ')')
			{
				if (temp.top() == '(')
					temp.pop();
				else
					return false;
			}
			else if (s[i] == ']')
			{
				if (temp.top() == '[')
					temp.pop();
				else
					return false;
			}
			else
			{
				if (temp.top() == '{')
					temp.pop();
				else
					return false;
			}
		}
	}
	if (temp.empty())
		return true;
	else
		return false;
}

int Solution::missingNumber(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i)
			return i;
	}
	return nums[nums.size()-1]+1;
}