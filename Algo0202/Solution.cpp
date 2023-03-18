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

	//��ϣ��			����ٶ�
	//unordered_set<int> s;
	//for (int i = 0; i < nums.size(); i++)
	//{
	//	if (s.find(nums[i]) != s.end())return true;
	//	s.insert(nums[i]);

	//}
	//return false;

	//����
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
		//����map����û��   ��ǰ�������� �� target �Ĳ�ֵ
		auto it = m.find(target - nums[i]);
		if (it != m.end())
		{
			
			return { it->second, i };
		}
		//key��¼ ��ֵ
		//value��¼ �±�
		m[nums[i]] = i;
	}
	return {};




}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = nums1.size() - 1;
	m--;
	n--;
	//��Ϊn<0֮��ʣ�µ����ö���m������Ҫ����λ�ã�n>=0Ϊ�������(nums2������֮ǰ)
	while (n >= 0)
	{
		//��Ҫ����m(����nums1)������
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
	//����2����ϣ����¼nums1ÿ��Ԫ�س��ִ�����Ȼ���ٱ���nums2��res��һ���ͼ�һ��value
}

int Solution::maxProfit(vector<int>& prices)
{
	//����һ��dp
	int s = prices.size();
	vector<int>dp(s);		//ÿ����������
	int ma = 0;
	int minprice = prices[0];
	for (int i = 1; i < s; i++)
	{
		minprice = min(minprice, prices[i]);
		//  ǰһ����������   ��   ����ļ۸�-��С�۸�
		dp[i] = max(dp[i - 1], prices[i] - minprice);
	}
	return dp[s - 1];

	//������������
	//����һ�����飬
	//���ϸ���minprice��maxprofit = max(maxprofit, todayprice - minprice) ����
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
