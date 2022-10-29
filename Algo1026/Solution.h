#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) : val(x), left(leftNode), right(rightNode) {}
};

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
	int maxDepth(TreeNode* root);
	bool isBalanced(TreeNode* root);
private:
	void quickSort(vector<int>& arr, int l, int r);
	int dfs1(TreeNode* Node);
	bool isBa = true;
};

