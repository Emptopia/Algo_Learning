#include "Solution.h"

void Solution::printVector(vector<int>& nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::printsVector(vector<string>& nums)
{
	for (vector<string>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

Solution::Solution(vector<int>& nums)
{
	origin = nums;
	current = nums;
	n = nums.size();
}




vector<int> Solution::reset()
{
	current = origin;
	return current;
}

vector<int> Solution::shuffle()
{
	for (int i = 0; i < n; i++)
	{
		int target_i = i + rand() % (n - i);				//一般性：rand() % (b-a+1) + a ;    就表示  a~b 之间的一个随机整数。

		int temp = current[i];
		current[i] = current[target_i];
		current[target_i] = temp;
	}
	return current;
}



vector<string>  Solution::fizzBuzz(int n)
{
	vector<string>res(n);
	for (int i = 1; i < n+1; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			res[i-1] = "FizzBuzz";
		else if (i % 3 == 0)
			res[i-1] = "Fizz";
		else if (i % 5 == 0)
			res[i-1] = "Buzz";
		else
			res[i-1] = to_string(i);
	}
	return res;
}

int Solution::countPrimes(int n)
{
	vector<int> isPrime(n, 1);			//10个1
	int ans = 0;
	for (int i = 2; i < n; ++i) 
	{
		if (isPrime[i]) 
		{
			ans += 1;											//没被排除掉的是质数(以及初始的2)
			if ((long long)i * i < n)						//当存在自身倍数时
			{
				for (int j = i * i; j < n; j += i)			//排除掉自身的倍数  
				{
					isPrime[j] = 0;
				}
			}
		}
	}
	return ans;

}

bool Solution::isPowerOfThree(int n)
{
	if (n == 1)
		return true;
	long long temp = 3;
	while (temp <= n)
	{
		if (temp == n)
			return true;
		temp = 3 * temp;
	}
	return false;
}

int Solution::romanToInt(string s)
{
	int res = 0;
	int length = s.size();
	for (int i = 0; i < length; i++)
	{
		int value = symbolValues[s[i]];
		if (i < length - 1 && value < symbolValues[s[i + 1]])
			res -= value;
		else
			res += value;
	}
	return res;
}

