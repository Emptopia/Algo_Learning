#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>
#include<set>
class Solution
{
public:

	template<typename T>
	void Tprint(vector<T>t1)
	{
		for (auto it = t1.begin(); it != t1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	template<typename T>
	void TTprint(vector<vector<T>>v)
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			for (auto itt = it->begin(); itt != it->end(); itt++)
			{
				cout << *itt << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	//void Vprint(vector<int>v);
	//void VVprint(vector<vector<int>>v);
	void Sprint(set<int>v);

	int pivotIndex(vector<int>& nums);
	int searchInsert(vector<int>& nums, int target);
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	bool isMerge(vector<int>v1, vector<int>v2);
	void rotate(vector<vector<int>>& matrix);
	void setZeroes(vector<vector<int>>& matrix);
	vector<int> findDiagonalOrder(vector<vector<int>>& mat);
	string longestCommonPrefix(vector<string>& strs);
	string longestPalindrome(string s);
	string reverseWords(string s);
	int strStr(string haystack, string needle);

	int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB);
	int transportationHub(vector<vector<int>>& path);
	vector<vector<int>> ballGame(int num, vector<string>& plate);

	void reverseString(vector<char>& s);
	int arrayPairSum(vector<int>& nums);
	vector<int> twoSum(vector<int>& numbers, int target);
};

