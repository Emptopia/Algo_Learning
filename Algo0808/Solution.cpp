#include "Solution.h"

void Solution::printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::printVector(vector<char>& v)
{
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::printMatrix(vector<vector<int>>& v)
{

	for (vector<vector<int>>::iterator rowit = v.begin(); rowit != v.end(); rowit++)
	{
		for (vector<int>::iterator colit = rowit->begin(); colit != rowit->end(); colit++)
		{
			cout << *colit << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Solution::rotate(vector<vector<int>>& matrix)
{
	if (matrix.size() == 1)
		return;
	int n = matrix.size()-1;
	int x = 0;
	do
	{
		for (int i = 0; i < n - 2*x; i++)
		{
			int temp = matrix[i+x][n-x];
			matrix[i+x][n-x] = matrix[x][i+x];
			int temp2 = matrix[n-x][n - i-x];
			matrix[n-x][n - i-x] = temp;
			int temp3 = matrix[n - i-x][x];
			matrix[n - i-x][x] = temp2;
			matrix[x][i+x] = temp3;
		}
		x++;
	} while (x < matrix.size() - 2);


	
}

void Solution::reverseString(vector<char>& s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		char temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
	}
}