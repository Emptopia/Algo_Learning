#include<vector>
#include<list>
#include<iostream>
using namespace std;
#include"Solution.h"

void Solution::printArray(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int Solution::removeDuplicates(vector<int>& nums)
{
    //0726
    if (nums.empty())
        return 0;
    int left = 0;
    for (int right = 1; right < nums.size(); right++)
    {
        if (nums[left] != nums[right])
        {
            left++;
            nums[left] = nums[right];
        }
    }
    return ++left;


    //if (nums.empty())
    //    return 0; // 空数组的判断
    //int left = 0;
    //for (int right = 1; right < (nums.size()); right++) {
    //    if (nums[left] != nums[right])
    //    { // 发现和后一个不相同
    //        nums[++left] = nums[right];
    //        //left = 0 的数据一定是不重复的，所以直接 ++left
    //    }
    //}
    //return ++left; //别忘了left是从0开始的，所以返回left+ 1
}

int Solution::maxProfit(vector<int>& prices)
{
    if (prices.empty())
        return 0;
    int profit = 0;
    for (int i = 0; i < prices.size()-1; i++)
    {
        if (prices[i] < prices[i + 1])
            profit += (prices[i + 1] - prices[i]);
    }
    return profit;
}

void Solution::rotateArray(vector<int>& nums, int k)
{
    if (nums.empty() || k<0)
        return;
    int mink = k % nums.size();
    cout << mink << endl;
    vector<int> nums2(nums.size() + mink);
    for (int i = 0; i < nums.size(); i++)
    {
        nums2[i + mink] = nums[i];
    }
    for (int i = 0; i < mink; i++)
    {
        nums2[i] = nums2[nums.size() + i];
    }
    nums2.resize(nums.size());
    nums = nums2;
}

