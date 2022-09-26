#include "Solution.h"

int Solution::removeElement(vector<int>& nums, int val)
{
	int slow = 0;
	for (int fast = 0; fast < nums.size(); fast++)
	{
		if (nums[fast] != val)
		{
			nums[slow] = nums[fast];
			slow++;
		}
	}
	return slow;
}

int Solution::findMaxConsecutiveOnes(vector<int>& nums)
{
	int temp = 0;
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
		{
			temp++;
		}
		else
		{
			res = max(res, temp);
			temp = 0;
		}
	}
	res = max(res, temp);
	return res;

}

int Solution::minSubArrayLen(int target, vector<int>& nums)
{
	//暴力超时
	//int res = INT_MAX;
	//int sum = 0;
	//for (int i = 0; i < nums.size(); i++)
	//{
	//	sum = 0;
	//	for (int j = i; j < nums.size(); j++)
	//	{
	//		sum += nums[j];
	//		if (sum >= target)
	//		{
	//			res = min(res, j - i + 1);
	//			break;
	//		}
	//	}
	//}
	//res = res == INT_MAX ? 0 : res;
	//return res;

	//双指针：滑动窗口！！
	int fast = 0;
	int slow = 0;
	int sum = 0;
	int res = INT_MAX;
	while (fast < nums.size())
	{
		sum += nums[fast];
		while (sum >= target)
		{
			res = min(res, fast - slow + 1);
			sum -= nums[slow];
			slow++;
		}
		fast++;

	}
	res = res == INT_MAX ? 0 : res;
	return res;

}