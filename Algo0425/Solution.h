#pragma once
#include<vector>
using namespace std;
#include<queue>
#include<algorithm>
#include<iostream>

class Solution
{
public:
	template<typename T>
	void Tprint(vector<T>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	vector<int> getLeastNumbers(vector<int>& arr, int k);

private:
	void quickSort1(vector<int>& arr, int l, int r);
	void quickSort2(vector<int>& arr, int k, int l, int r);
};

