#pragma once
using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
class Solution
{
public:
	void printVector(vector<int>&v);
	void printVector(vector<char>& v);
	void printMatrix(vector<vector<int>>&v);

	void rotate(vector<vector<int>>& matrix);
	void reverseString(vector<char>& s);
	int reverse(int x);
	int firstUniqChar(string s);
	bool isAnagram(string s, string t);
};

