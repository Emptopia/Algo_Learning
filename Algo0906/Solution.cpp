#include "Solution.h"

void Solution::printVector(vector<int>& nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

Solution::Solution(vector<int>& nums)
{
	origin = nums;
	current = nums;
	n = nums.size();
}

vector<int> Solution::reset()
{
	current = origin;
	return current;
}

vector<int> Solution::shuffle()
{
	for (int i = 0; i < n; i++)
	{
		int target_i = i + rand() % (n - i);				//һ���ԣ�rand() % (b-a+1) + a ;    �ͱ�ʾ  a~b ֮���һ�����������

		int temp = current[i];
		current[i] = current[target_i];
		current[target_i] = temp;
	}
	return current;
}
