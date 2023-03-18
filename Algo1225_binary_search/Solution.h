#pragma once
#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
	//一、二分查找四模板
	// 查找相等值，找不到返回-1
	//1、左闭右闭，相错终止(l=r+1时，nums被分完)
	int search1(vector<int>& nums, int target)
	{
		//四要素
		int l = 0, r = nums.size() - 1;//①初值
		while (l <= r)//②条件
		{
			int m = l + (r - l) / 2;//③中间值
			if (nums[m] == target)return m;
			else if (nums[m] < target)l = m + 1;//④左右界
			else r = m - 1;
		}
		return -1;
	}
	//2、左闭右开，相等终止(l=r时，nums被分完)
	int search2(vector<int>& nums, int target)
	{
		//1、若初始 l = 0, r = nums.size() - 1
		//那么由于 while的条件是l<r，当 nums 只有一个元素时，将无法进入 while
		//2、当 target 大于 nums中所有元素时，r = nums.length将是这一情况的一个标志，
		//倘若初始 r = nums.size() - 1，只看 r 的最终取值是无法判断为上述情况的，仍需要比较一次target 与 nums 中的最后一个元素。

		int l = 0, r = nums.size();
		while (l < r)//r取不到，故不取等号
		{
			int m = l + (r - l) / 2;
			if (nums[m] == target)return m;
			else if (nums[m] < target)l = m + 1;
			else r = m;//r取不到，右界不用减1
		}
		return -1;
	}
	//3、左开右闭，相等终止
	int search3(vector<int>& nums, int target)
	{
		int l = -1, r = nums.size()-1;
		while (l < r)//l取不到，故不取等号
		{
			int m = l + (r - l + 1) / 2;//这里要向上取整
			if (nums[m] == target) return m;
			else if (nums[m] < target) l = m;//l取不到，左界不用加1
			else r = m - 1;
		}
		return -1;
	}
	//4、左开右开，相邻终止
	int search4(vector<int>& nums, int target)
	{
		int l = -1, r = nums.size();
		while (l + 1 < r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] == target) return m;
			else if (nums[m] < target)l = m;
			else r = m;
		}
		return -1;
	}

	//二、二分查找四情形
	// 以左闭右闭为例
	//1、大于等于
	int search5(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] < target)l = m + 1;
			else r = m - 1;		//将相等并入大于
		}
		//return (l == nums.size() || nums[l] != target) ? -1 : l;			//用于寻找等于值时
		return l == nums.size() ? -1 : l;			//l越界时，nums不存在大于等于target的数
	}
	//2、大于
	int search6(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] <= target)l = m + 1;	//将相等并入小于，循环结束后，l左侧均为小于等于，r右侧均为大于
			else r = m - 1;
		}
		return l == nums.size() ? -1 : l;
	}
	//3、小于等于
	int search7(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] <= target)l = m + 1;	//将相等并入小于，循环结束后，l左侧均为小于等于，r右侧均为大于
			else r = m - 1;
		}
		return r;		//当l=0,r刚好等于-1
	}
	//4、小于
	int search8(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] < target) l = m + 1;
			else r = m - 1;
		}
		return r;
	}




};

