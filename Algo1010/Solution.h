#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution
{
public:
	template<typename T>
	void Tprint(vector<T>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	template<typename T>
	void TTprint(vector<vector<T>>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			for (auto itt = it->begin(); itt != it->end(); itt++)
			{
				cout << *itt << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);
	int minArray(vector<int>& numbers);
	char firstUniqChar(string s);

	//void helper1(TreeNode* root, vector<int>&res);
	vector<int> levelOrder(TreeNode* root);
	vector<vector<int>> levelOrder2(TreeNode* root);
	vector<vector<int>> levelOrder3(TreeNode* root);
	bool isSubStructure(TreeNode* A, TreeNode* B);
	TreeNode* mirrorTree(TreeNode* root);
	bool isSymmetric(TreeNode* root);


private:
	bool recur(TreeNode* A, TreeNode* B);
	void recur2(TreeNode* Node);
	bool recur3(TreeNode* A, TreeNode* B);

};


