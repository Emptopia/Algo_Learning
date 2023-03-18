#include "Solution.h"


bool Solution::containsDuplicate(vector<int>& nums)
{
	//unordered_map<int, int> m;

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	m[nums[i]]++;
	//	if (m[nums[i]] >= 2) return true;
	//}

	//return false;

	//哈希表			差不多速度
	//unordered_set<int> s;
	//for (int i = 0; i < nums.size(); i++)
	//{
	//	if (s.find(nums[i]) != s.end())return true;
	//	s.insert(nums[i]);

	//}
	//return false;

	//排序
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] == nums[i + 1])return true;

	}
	return false;
}

int Solution::maxSubArray(vector<int>& nums)
{
	vector<int>maxn(nums.size());
	maxn[0] = nums[0];
	int res = maxn[0];
	for (int i = 1; i < nums.size(); i++)
	{
		maxn[i] = max(maxn[i - 1] + nums[i], nums[i]);
		res = max(res, maxn[i]);


	}
	return res;





}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int>m;
	for (int i = 0; i < nums.size(); i++)
	{
		//查找map中有没有   当前遍历的数 和 target 的差值
		auto it = m.find(target - nums[i]);
		if (it != m.end())
		{
			
			return { it->second, i };
		}
		//key记录 数值
		//value记录 下标
		m[nums[i]] = i;
	}
	return {};




}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = nums1.size() - 1;
	m--;
	n--;
	//因为n<0之后，剩下的正好都是m，不需要调整位置，n>=0为外层条件(nums2后移完之前)
	while (n >= 0)
	{
		//需要调整m(后移nums1)的条件
		while (m >= 0 && nums1[m] > nums2[n])
		{
			nums1[i] = nums1[m];
			i--;
			m--;
		}
		nums1[i] = nums2[n];
		i--;
		n--;

	}


}

vector<int> Solution::intersect(vector<int>& nums1, vector<int>& nums2)
{
	vector<int>res;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	auto it1 = nums1.begin();
	auto it2 = nums2.begin();
	while (it1!=nums1.end() && it2!= nums2.end())
	{
		if (*it1 < *it2)it1++;
		else if (*it1 > *it2)it2++;
		else
		{
			res.push_back(*it1);
			it1++;
			it2++;
		}
	}
	return res;
	//方法2：哈希表，记录nums1每种元素出现次数，然后再遍历nums2，res加一个就减一个value
}

int Solution::maxProfit(vector<int>& prices)
{
	//方法一：dp
	int s = prices.size();
	vector<int>dp(s);		//每天的最大利润
	int ma = 0;
	int minprice = prices[0];
	for (int i = 1; i < s; i++)
	{
		minprice = min(minprice, prices[i]);
		//  前一天的最大利润   或   今天的价格-最小价格
		dp[i] = max(dp[i - 1], prices[i] - minprice);
	}
	return dp[s - 1];

	//方法二：遍历
	//遍历一次数组，
	//不断更新minprice和maxprofit = max(maxprofit, todayprice - minprice) 即可
}

vector<vector<int>> Solution::matrixReshape(vector<vector<int>>& mat, int r, int c)
{
	int i = 0, j = 0;
	int m = mat.size();
	int n = mat[0].size();
	if (m * n != r * c)return mat;
	vector<int>temp;
	vector<vector<int>>res;
	while (res.size() < r)
	{
		temp = {};
		while (temp.size() < c)
		{
			temp.push_back(mat[i][j]);
			if (j ==	 mat[0].size()-1)
			{
				i++;
				j = 0;
			}
			else j++;
		}
		res.push_back(temp);
	}



	return res;
}

vector<vector<int>> Solution::generate(int numRows)
{
	vector<vector<int>>res;
	for (int i = 0; i < numRows; i++)
	{
		res.push_back(vector<int>(i+1, 1));
	}
	for (int i = 2; i < numRows; i++)
	{
		for (int j = 1; j < res[i].size()-1; j++)
		{
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}



	return res;
}
