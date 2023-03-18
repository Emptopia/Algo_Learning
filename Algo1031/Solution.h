#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	double myPow(double x, int n);
	bool verifyPostorder(vector<int>& postorder);
	int hammingWeight(uint32_t n);
	int add(int a, int b);
	
private:
	int res1 = 0;
	bool isleaf(TreeNode* root, TreeNode* p);
	TreeNode* recur1(int root, int left, int right);
	vector<int>preorder;
	unordered_map<int, int>map1;
	bool recur2(vector<int>& postorder, int i, int j);
};

