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



TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	this->preorder = preorder;
	for (int i = 0; i < inorder.size(); i++)
		map1[inorder[i]] = i;			//建立一个dic，key为inorder的节点值，val为inorder的下标
													//用来快速查找节点值所在中序数组的位置
	return recur1(0, 0, inorder.size() - 1);
}
//root：当前根节点再pre中的索引
//left：子树在in中的左边界
//right：子树在in中的右边界
TreeNode* Solution::recur1(int root, int left, int right)
{
	if (left > right)return nullptr;		//左边界算出来大于右边界，递归终止
														//当left==right，子树为叶（好像
	TreeNode* node = new TreeNode(preorder[root]);		//建立当前根节点
	int i = map1[preorder[root]];			//找到inorder中当前root节点的位置
	//左子树
	//pre子树根节点：root+1
	//in子树左边界：left
	//in子树右边界：i-1				in中的root位置以左和left围成左右边界
	node->left = recur1(root + 1, left, i - 1);				
	//右子树
	//pre子树根节点：i - left + root + 1			这里i-left表示左子树节点数量，root+1代表pre中左子树根节点位置，
	//																相加就是pre中右子树根节点位置
	//in子树左边界：i+1
	//in子树右边界：right			in中的root位置以右和right围成左右边界
	node->right = recur1(root + i - left + 1, i + 1, right);
	return node;
}

double Solution::myPow(double x, int n)
{
	if (x == 0.0f)return 0.0;
	long b = n;				//b：剩余次数
	double res = 1.0;
	if (b < 0)					//当幂小于0，将问题转化成大于0的形式
	{
		x = 1 / x;				//x^(-n)=(1/x)^n
		b = -b;				
	}
	while (b > 0)		
	{
		if ((b & 1) == 1)res *= x;			//剩余次数为奇数时，将多出的一项x乘入res，
														//最终x^n=x^0×res;      x^n是多平方了一次，返回res即可
		x *= x;			//执行x=x^2
		b >>= 1;		//b右移一位，即剩余次数整除2
	}
	return res;

}

bool Solution::verifyPostorder(vector<int>& postorder)
{
	//后序遍历：左右根
	return recur2(postorder, 0, postorder.size() - 1);

}

bool Solution::recur2(vector<int>& postorder, int i, int j)
{
	if (i >= j)return true;
	int p = i;
	while (postorder[p] < postorder[j])p++;
	int m = p;
	while (postorder[p] > postorder[j])p++;
	return p == j && recur2(postorder, i, m - 1) && recur2(postorder, m, j - 1);

}

int Solution::hammingWeight(uint32_t n)
{
	int res = 0;
	while (n != 0)
	{
		if ((n & 1) == 1)
			res++;
		n = n >> 1;
	}
	return res;
}

int Solution::add(int a, int b)
{
	while (b != 0)
	{
		int c = (unsigned int)(a & b) << 1;	// c = 进位
		a = a ^ b;						// a = 非进位和
		b = c;							// b = 进位
	}
	return a;
}
