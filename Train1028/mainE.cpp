#include<iostream>
using namespace std;
#include<vector>
#include <limits.h>

int main()
{
	//n人数，步骤
	//m小组数
	int n, m;
	cin >> n >> m;
	vector<vector<int>>nums(m,vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums[i][j];
		}
	}
	//dp[j][i]代表第j组遍历到第i个人(第i步)最少的天数
	//dp[j][i] = min (dp[j][i-1],dp[j-1][i-1]) + nums[j][i]
	vector<vector<int>>dp(m, vector<int>(n));
	for (int j = 0; j < m; j++)
	{
		dp[j][0] = nums[j][0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				dp[j][i] = min(dp[j][i - 1], dp[m-1][i - 1]) + nums[j][i];
			}
			else
			{
				dp[j][i] = min(dp[j][i - 1], dp[j - 1][i - 1]) + nums[j][i];
			}
		}
	}
	int mi = INT_MAX;
	for (int i = 0; i < m; i++)
	{
		mi = min(mi, dp[i][n - 1]);
	}
	cout << mi << endl;





	system("pause");
	return 0;

}