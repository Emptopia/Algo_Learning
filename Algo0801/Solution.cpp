#include"Solution.h"

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

//int Solution::singleNumber(vector<int>& nums)					//很麻烦的排序法
//{
//	sort(nums.begin(),nums.end());
//	vector<int>::iterator it = nums.begin();
//	while (true)
//	{
//		it = adjacent_find(nums.begin(), nums.end());
//		if (it == nums.end())
//			break;
//		//cout << "删除相邻" << *it << endl;
//		it = nums.erase(it);
//		nums.erase(it);
//	}
//	//cout << "返回" << *(nums.begin()) << endl;
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

void Solution::moveZeroes(vector<int>& nums)
{
	int index = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
			nums[index++] = nums[i];
	}
	while (index < nums.size())
		nums[index++] = 0;
}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> hashtable;
	for (int i = 0; i < nums.size(); ++i) {
		auto it = hashtable.find(target - nums[i]);
		if (it != hashtable.end()) {
			return { it->second, i };						//it(value,key)
		}
		hashtable[nums[i]] = i;
	}
	return {};

}

//bool Solution::isValidSudoku(vector<vector<char>>& board)				//自己实现部分基于map的insert判断
//{
//	set<char>s1;
//	set<char>s2;
//	set<char>s3;
//
//	for (int i = 0; i < 9; i++)
//	{
//		s1.clear();
//		s2.clear();
//		for (int j = 0; j < 9; j++)
//		{
//			if (board[i][j] != '.')
//			{
//				pair<set<char>::iterator, bool> ret1 = s1.insert(board[i][j]);
//				if (ret1.second == false)
//					return false;
//			}
//			if (board[j][i] != '.')
//			{
//				pair<set<char>::iterator, bool> ret2 = s2.insert(board[j][i]);
//				if (ret2.second == false)
//					return false;
//			}
//		}
//	}
//
//
//	return true;
//}

bool Solution::isValidSudoku(vector<vector<char>>& board)
{
	int row[9][9];
	int column[9][9];
	int subboxes[3][3][9];
	memset(row, 0, sizeof(row));
	memset(column, 0, sizeof(column));
	memset(subboxes, 0, sizeof(subboxes));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char c = board[i][j];
			if (c != '.')
			{
				int index = c - '0' - 1;
				row[i][index]++;
				column[j][index]++;
				subboxes[i / 3][j / 3][index]++;
				if (row[i][index] > 1 || column[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1)
					return false;
			}
		}
	}
	return true;












	//int rows[9][9];
	//int columns[9][9];
	//int subboxes[3][3][9];

	//memset(rows, 0, sizeof(rows));
	//memset(columns, 0, sizeof(columns));
	//memset(subboxes, 0, sizeof(subboxes));
	//for (int i = 0; i < 9; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		char c = board[i][j];
	//		if (c != '.') {
	//			int index = c - '0' - 1;			//此处'5'-'0'的ascii码值，即为5的int值，数字有1-9，对应index有0-8，故-1
	//			rows[i][index]++;
	//			columns[j][index]++;
	//			subboxes[i / 3][j / 3][index]++;
	//			if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) {
	//				return false;
	//			}
	//		}
	//	}
	//}
	//return true;

}