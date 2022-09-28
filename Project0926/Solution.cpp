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

vector<vector<int>> Solution::generate(int numRows)
{
	vector<vector<int>>res(numRows);
	if (numRows == 1)
		return { {1} };
	if (numRows == 2)
		return { {1} ,{1,1} };
	res[0] = { 1 };
	res[1] = { 1,1 };
	for (int i = 2; i < numRows; i++)
	{
		res[i].resize(i+1);
		res[i][0] = res[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res;
}

vector<int> Solution::getRow(int rowIndex)
{
	vector<int> result(rowIndex + 1, 1);
	if (rowIndex < 2)
	{
		return result;
	}
	// 需要进行迭代的次数
	for (int i = 1; i < rowIndex; i++)
	{
		// 每次迭代进行的计算
		for (int j = i; j > 0; j--)
		{
			result[j] = result[j] + result[j - 1];
		}
	}
	return result;
}

int Solution::findMin(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;                /* 左闭右闭区间，如果用右开区间则不方便判断右值 */
	while (left < right) {                      /* 循环不变式，如果left == right，则循环结束 */
		int mid = left + (right - left) / 2;    /* 地板除，mid更靠近left */
		if (nums[mid] > nums[right]) {          /* 中值 > 右值，最小值在右半边，收缩左边界 */
			left = mid + 1;                     /* 因为中值 > 右值，中值肯定不是最小值，左边界可以跨过mid */
		}
		else if (nums[mid] < nums[right]) {   /* 明确中值 < 右值，最小值在左半边，收缩右边界 */
			right = mid;                        /* 因为中值 < 右值，中值也可能是最小值，右边界只能取到mid处 */
		}
	}
	return nums[left];    /* 循环结束，left == right，最小值输出nums[left]或nums[right]均可 */

}