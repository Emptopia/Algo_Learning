#include<vector>
#include<list>
#include<iostream>
using namespace std;
#include"Solution.h"


int Solution::removeDuplicates(vector<int>& nums)
{
    if (nums.empty())
        return 0; // 空数组的判断
    int left = 0;
    for (int right = 1; right < (nums.size()); right++) {
        if (nums[left] != nums[right])
        { // 发现和后一个不相同
            nums[++left] = nums[right];
            //left = 0 的数据一定是不重复的，所以直接 ++left
        }
    }
    return ++left; //别忘了left是从0开始的，所以返回left+ 1
}

