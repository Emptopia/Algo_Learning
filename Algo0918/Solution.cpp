#include "Solution.h"
void Solution::Vprint(vector<int>v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::VVprint(vector<vector<int>>v)
{
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator itt = it->begin(); itt != it->end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Solution::pivotIndex(vector<int>& nums)
{
	//1、前后相加
	//int len = nums.size();
	//int prev = 0;
	//int back = accumulate(nums.begin(), nums.end(), 0);			//numeric 头文件
	//for (int i = 0; i < len; i++)
	//{
	//	back -= nums[i];
	//	if (prev == back)
	//		return i;
	//	prev += nums[i];
	//}
	//return -1;


	//2、求前缀和					//复杂度差不多
	int len = nums.size();
	int prev = 0;
	int total = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < len; i++)
	{
		if (2 * prev + nums[i] == total)			//前缀*2 + 当前下标数 = 总和
			return i;
		prev += nums[i];
	}
	return -1;
}

int Solution::searchInsert(vector<int>& nums, int target)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] >= target)
			return i;
	}
	return len;
}

bool Solution::isMerge(vector<int>v1, vector<int>v2)
{
	return ((v2[0] <= v1[1] && v2[0] >= v1[0])
		|| (v2[1] <= v1[1] && v2[1] >= v1[0])
		|| (v1[0] <= v2[1] && v1[0] >= v2[0])
		|| (v1[1] <= v2[1] && v1[1] >= v2[0]));
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int>>res;
	for (int i = 0; i < intervals.size(); i++)
	{
		int L = intervals[i][0], R = intervals[i][1];
		if (!res.size() || res.back()[1] < L)					//没有原区间 或 下个区间左端 小于 原区间右端时
			res.push_back(intervals[i]);						//插入下个区间
		else
		{
			res.back()[1] = max(res.back()[1], R);		//原区间右端改成 最大右端
		}
	}
	return res;
}

void Solution::rotate(vector<vector<int>>& matrix)
{
	int len = matrix.size();
	int temp;
	for (int j = 0; j < len - 1; j++)
	{
		for (int i = 0; i < len - 1- 2*j ; i++)
		{
			temp = matrix[j][j + i];
			matrix[j][j + i] = matrix[len - 1 - i - j][j];
			matrix[len - 1 - i - j][j] = matrix[len - 1 - j][len - 1 - i - j];
			matrix[len - 1 - j][len - 1 - i - j] = matrix[i + j][len - 1 - j];
			matrix[i + j][len - 1 - j] = temp;
		}
	}

}

void Solution::setZeroes(vector<vector<int>>& matrix)
{
	vector<int>row;
	vector<int>column;
	int rsize = matrix.size();
	int csize = matrix[0].size();
	for (int i = 0; i < rsize; i++)
	{
		for (int j = 0; j < csize; j++)
		{
			if (matrix[i][j] == 0)
			{
				row.push_back(i);
				column.push_back(j);			//用两个数组记录需要清除的行列
			}
		}
	}
	for (int i = 0; i < row.size(); i++)		//清零行
	{
		for (int j = 0; j < csize; j++)
			matrix[row[i]][j] = 0;
	}
	for (int i = 0; i < column.size(); i++)		//清零列
	{
		for (int j = 0; j < rsize; j++)
			matrix[j][column[i]] = 0;
	}
	return;
}

vector<int> Solution::findDiagonalOrder(vector<vector<int>>& mat)
{
	vector<int>res;
	res.push_back(mat[0][0]);
	int m = mat.size();
	int n = mat[0].size();
	int row = 0;
	int column = 0;
	while (true)
	{
		//判断是否遍历到最后一位
		if (row == m - 1 && column == n - 1)		
			break;
		//往右上遍历
		while (row !=0 && column!=n-1)            //右上能走，循环右上
		{
			row--;
			column++;
			res.push_back(mat[row][column]);
		}
		if (row == 0 && column != n - 1)            //到第一行，非最后一列：列下标+1
			column++;
		else                                                           //其他情况：行下标+1
			row++;
		res.push_back(mat[row][column]);

		//判断是否遍历到最后一位
		if (row == m - 1 && column == n - 1)
			break;
		//往左下遍历
		while (row != m - 1 && column != 0)       //左下能走，循环左下
		{
			row++;
			column--;
			res.push_back(mat[row][column]);  
		}
		if (row != m - 1 && column ==0)          //到第一列，非最后一行：行下标+1
			row++;
		else                                                         //其他情况：列下标+1
			column++;
		res.push_back(mat[row][column]);        

	}
	return res;
}

string Solution::longestCommonPrefix(vector<string>& strs)
{
	string res = strs[0];							
	for (int i = 1; i < strs.size(); i++)
	{
		for (int j = 0; j < strs[i].size() && j < res.size(); j++)
		{
			if (strs[i][j] != res[j])					//遍历到不同字母时，resize前一个下标的长度
			{
				res.resize(j);
			}
		}
		if (res.size() > strs[i].size())			//补充下一个字符串比公共前缀还短的情况
			res = strs[i];
	}
	return res;

	//还有个方法：第一遍直接遍历所有成员的首字母，相同则push_back到res，依此类推。
}

string Solution::longestPalindrome(string s)
{
	//动态规划：记住求过的解来节省时间
	int n = s.size();
	if (n < 2) {
		return s;
	}

	int maxLen = 1;
	int begin = 0;
	// dp[i][j] 表示 s[i]到s[j] 是否是回文串			
	vector<vector<int>> dp(n, vector<int>(n));				//创建了n个	 大小为n  的vector<int>		(成员都是0)
	// 初始化：所有长度为 1 的子串都是回文串
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;															//此前所有成员为0，即false
	}
	// 递推开始
	// 先枚举子串长度
	for (int L = 2; L <= n; L++) {
		// 枚举左边界，左边界的上限设置可以宽松一些
		for (int i = 0; i < n; i++) {
			// 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
			int j = L + i - 1;
			// 如果右边界越界，就可以退出当前循环
			if (j >= n) {
				break;
			}

			if (s[i] != s[j]) {
				dp[i][j] = false;
			}
			else {												//左端等于右端时，分以下2种情况
				if (j - i < 3) {
					dp[i][j] = true;							//没有子串时，本串就是回文串
				}
				else {
					dp[i][j] = dp[i + 1][j - 1];			//子串是回文串时，本串也是回文串，反之
				}
			}

			// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
			if (dp[i][j] && j - i + 1 > maxLen) {				//从右往左，左右端点比最大记录大，并本串是回文时，执行if语句
				maxLen = j - i + 1;
				begin = i;
			}
		}
	}
	return s.substr(begin, maxLen);
}

string Solution::reverseWords(string s)
{
	//逻辑混乱，待改进
	string res = "";
	int temp = 0;
	string test;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			test = s.substr(i + 1, temp);
			if (test != "")
			{
				res += test;
				res += " ";			//第一位为空格时，此步会执行，插到res末位，故在278行删除
			}
			temp = 0;
		}
		else
		{
			temp++;
		}
	}
	res += s.substr(0, temp);
	if (res.back() == ' ')						
		res.resize(res.size() - 1);			//278
	return res;

}