#include "Solution.h"

int Solution::sumNums(int n)
{
	n > 1 && sumNums(n - 1);		//利用&&的截断，达成if的效果
	res1 += n;
	return res1;
}

TreeNode* Solution::lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root->val < p->val && root->val < q->val)
		return lowestCommonAncestor1(root->right, p, q);
	if (root->val > p->val && root->val > q->val)
		return lowestCommonAncestor1(root->left, p, q);
	return root;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
	if (isleaf(root->left, p) && isleaf(root->left, q))
		return lowestCommonAncestor(root->left, p, q);
	if (isleaf(root->right, p) && isleaf(root->right, q))
		return lowestCommonAncestor(root->right, p, q);
	return root;
}
bool Solution::isleaf(TreeNode* root, TreeNode* p)
{
	if (root == nullptr)
		return false;
	else if (root == p)
		return true;
	else
		return isleaf(root->left, p) || isleaf(root->right, p);
}
