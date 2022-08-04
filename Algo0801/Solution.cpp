#include"Solution.h"
#include<algorithm>

void Solution::printVector(vector<int>& nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool Solution::containsDuplicate(vector<int>& nums)
{
	if (nums.empty())
		return false;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	
	return false;
}

int Solution::singleNumber(vector<int>& nums)
{
	int sNum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sNum = sNum ^ nums[i];
		cout << sNum << endl;
	}
	return sNum;
}

//int Solution::singleNumber(vector<int>& nums)					//ºÜÂé·³µÄÅÅĞò·¨
//{
//	sort(nums.begin(),nums.end());
//	vector<int>::iterator it = nums.begin();
//	while (true)
//	{
//		it = adjacent_find(nums.begin(), nums.end());
//		if (it == nums.end())
//			break;
//		//cout << "É¾³ıÏàÁÚ" << *it << endl;
//		it = nums.erase(it);
//		nums.erase(it);
//	}
//	//cout << "·µ»Ø" << *(nums.begin()) << endl;
//	return*(nums.begin());
//}


vector<int> Solution::intersect(vector<int>& nums1, vector<int>& nums2)
{
	vector<int>::iterator pos;
	vector<int>nums3;
	while (!nums1.empty())
	{
		pos = find(nums2.begin(), nums2.end(), *(nums1.begin()));
		if (pos != nums2.end())
		{
			nums3.push_back(*pos);
			nums2.erase(pos);
		}
		nums1.erase(nums1.begin());
	}
	return nums3;
}

vector<int> Solution::plusOne(vector<int>& digits)
{
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] == 9)
			digits[i] = 0;
		else
		{
			digits[i]++;
			break;
		}
		if (i == 0)
		{
			digits[i] = 1;
			digits.push_back(0);
		}
	}
	return digits;
}