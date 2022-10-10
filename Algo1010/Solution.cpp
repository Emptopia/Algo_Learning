#include "Solution.h"

bool Solution::findNumberIn2DArray(vector<vector<int>>&matrix, int target)
{
	if (matrix.empty())
		return false;
	int row = matrix.size();
	int column = matrix[0].size();
	//1������
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < column; j++)
	//	{
	//		if (matrix[i][j] == target)
	//			return true;
	//	}
	//}
	//return false;

	//2�����������					//��������������ʱ��Ц��
	int i = row - 1;
	int j = 0;
	while (i >= 0 && j < column)
	{
		if (matrix[i][j] > target)
			i--;
		else if (matrix[i][j] < target)
			j++;
		else
			return true;
	}
	return false;
}

int Solution::minArray(vector<int>& numbers)
{
	//����
	//for (int i = 0; i < numbers.size()-1; i++)
	//{
	//	if (numbers[i] > numbers[i + 1])
	//		return numbers[i + 1];
	//}
	//return numbers[0];

	//����
	int left = 0;
	int right = numbers.size() - 1;
	while (left < right)
	{
		int m = (left + right) / 2;
		if (numbers[m] > numbers[right])
			left = m + 1;
		else if (numbers[m] < numbers[right])
			right = m;
		else
			right--;
	}
	return numbers[left];
}

char Solution::firstUniqChar(string s)
{
	map<char, int>m;
	for (char i : s)
	{
		m[i]++;
	}
	for (char i : s)
	{
		if (m[i] == 1)
			return i;
	}
	return ' ';
}