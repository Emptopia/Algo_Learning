#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>
class Solution
{
public:
	void Vprint(vector<int>v);
	void VVprint(vector<vector<int>>v);
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
};

