#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    vector<int>nums = {1,2,3,4,5,6,7};
    
    int res = sln.search(nums, 5);
    cout << res << endl;
}