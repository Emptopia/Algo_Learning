#include"Solution.h"
#include<algorithm>

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