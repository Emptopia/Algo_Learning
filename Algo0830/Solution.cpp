#include "Solution.h"

void Solution::printVector(vector<int>nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int>res = vector<int>();
	int left = 0;
	int right = 0;
	while (left != m && right != n)
	{
		if (nums1[left] < nums2[right])
		{
			res.push_back(nums1[left]);
			left++;
		}
		else
		{
			res.push_back(nums2[right]);
			right++;
		}
	}
	if (left == m )
	{
		while (right != n )
		{
			res.push_back(nums2[right]);
			right++;
		}
	}
	else
	{
		while (left != m )
		{
			res.push_back(nums1[left]);
			left++;
		}
	}
	
	nums1 = res;
}

int Solution::firstBadVersion(int n)
{
	int left = 1, right = n;
	while (left < right)	// ѭ��ֱ���������Ҷ˵���ͬ
	{ 
		int mid = left + (right - left) / 2; // ��ֹ����ʱ���
		if (isBadVersion(mid)) 
		{
			right = mid; // �������� [left, mid] ��
		}
		else 
		{
			left = mid + 1; // �������� [mid+1, right] ��
		}
	}
	// ��ʱ�� left == right��������Ϊһ���㣬��Ϊ��
	return left;

}

bool Solution::isBadVersion(int version)
{
	int bad = 4;
	if (version >= bad)
		return true;
	else
		return false;
}

int Solution::climbStairs(int n)
{
	/* ��̬�滮�岿����
	   * 1.ȷ��dp[i]���±��Լ�dpֵ�ĺ��壺 ������i��¥�ݣ���dp[i]�ַ�����
	   * 2.ȷ����̬�滮�ĵ��ƹ�ʽ��dp[i] = dp[i-1] + dp[i-2];
	   * 3.dp����ĳ�ʼ������Ϊ��ʾ�У�1<=n<=45 ���Գ�ʼ��ֵ��dp[1] = 1, dp[2] = 2;
	   * 4.ȷ������˳�򣺷������ƹ�ʽ��֪��ǰֵ����ǰ����ֵ��ȷ�������Ե���˳��Ӧ���Ǵ�ǰ����
	   * 5.��ӡdp���鿴�Լ�д�ĶԲ��ԣ�
	  */
	if (n <= 1) return n;
	/* ����dp���� */
	vector<int> dp(n + 1);			//size��n+1,�ſ���ѭ����dp[n]			,dp[0]+dp[1] = dp[2] = 2
	/* ��ʼ��dp���� */
	dp[1] = 1;
	dp[2] = 2;
	/* ��ǰ������� */
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];

}