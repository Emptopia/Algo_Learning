#pragma once
#include<iostream>
using namespace std;
#include<vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* LeftNode, TreeNode* RightNode) : val(x), left(LeftNode), right(RightNode) {}
	
};
class Solution
{
public:
	int sumNums(int n);
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q);
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
private:
	int res1 = 0;
	bool isleaf(TreeNode* root, TreeNode* p);

};

