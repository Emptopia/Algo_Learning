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
	//1��ǰ�����
	//int len = nums.size();
	//int prev = 0;
	//int back = accumulate(nums.begin(), nums.end(), 0);			//numeric ͷ�ļ�
	//for (int i = 0; i < len; i++)
	//{
	//	back -= nums[i];
	//	if (prev == back)
	//		return i;
	//	prev += nums[i];
	//}
	//return -1;


	//2����ǰ׺��					//���ӶȲ��
	int len = nums.size();
	int prev = 0;
	int total = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < len; i++)
	{
		if (2 * prev + nums[i] == total)			//ǰ׺*2 + ��ǰ�±��� = �ܺ�
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
		if (!res.size() || res.back()[1] < L)					//û��ԭ���� �� �¸�������� С�� ԭ�����Ҷ�ʱ
			res.push_back(intervals[i]);						//�����¸�����
		else
		{
			res.back()[1] = max(res.back()[1], R);		//ԭ�����Ҷ˸ĳ� ����Ҷ�
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
				column.push_back(j);			//�����������¼��Ҫ���������
			}
		}
	}
	for (int i = 0; i < row.size(); i++)		//������
	{
		for (int j = 0; j < csize; j++)
			matrix[row[i]][j] = 0;
	}
	for (int i = 0; i < column.size(); i++)		//������
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
		//�ж��Ƿ���������һλ
		if (row == m - 1 && column == n - 1)		
			break;
		//�����ϱ���
		while (row !=0 && column!=n-1)            //�������ߣ�ѭ������
		{
			row--;
			column++;
			res.push_back(mat[row][column]);
		}
		if (row == 0 && column != n - 1)            //����һ�У������һ�У����±�+1
			column++;
		else                                                           //������������±�+1
			row++;
		res.push_back(mat[row][column]);

		//�ж��Ƿ���������һλ
		if (row == m - 1 && column == n - 1)
			break;
		//�����±���
		while (row != m - 1 && column != 0)       //�������ߣ�ѭ������
		{
			row++;
			column--;
			res.push_back(mat[row][column]);  
		}
		if (row != m - 1 && column ==0)          //����һ�У������һ�У����±�+1
			row++;
		else                                                         //������������±�+1
			column++;
		res.push_back(mat[row][column]);        

	}
	return res;
}