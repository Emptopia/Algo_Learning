#include "Solution.h"

int Solution::sumNums(int n)
{
	n > 1 && sumNums(n - 1);		//����&&�Ľضϣ����if��Ч��
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
		map1[inorder[i]] = i;			//����һ��dic��keyΪinorder�Ľڵ�ֵ��valΪinorder���±�
													//�������ٲ��ҽڵ�ֵ�������������λ��
	return recur1(0, 0, inorder.size() - 1);
}
//root����ǰ���ڵ���pre�е�����
//left��������in�е���߽�
//right��������in�е��ұ߽�
TreeNode* Solution::recur1(int root, int left, int right)
{
	if (left > right)return nullptr;		//��߽�����������ұ߽磬�ݹ���ֹ
														//��left==right������ΪҶ������
	TreeNode* node = new TreeNode(preorder[root]);		//������ǰ���ڵ�
	int i = map1[preorder[root]];			//�ҵ�inorder�е�ǰroot�ڵ��λ��
	//������
	//pre�������ڵ㣺root+1
	//in������߽磺left
	//in�����ұ߽磺i-1				in�е�rootλ�������leftΧ�����ұ߽�
	node->left = recur1(root + 1, left, i - 1);				
	//������
	//pre�������ڵ㣺i - left + root + 1			����i-left��ʾ�������ڵ�������root+1����pre�����������ڵ�λ�ã�
	//																��Ӿ���pre�����������ڵ�λ��
	//in������߽磺i+1
	//in�����ұ߽磺right			in�е�rootλ�����Һ�rightΧ�����ұ߽�
	node->right = recur1(root + i - left + 1, i + 1, right);
	return node;
}

double Solution::myPow(double x, int n)
{
	if (x == 0.0f)return 0.0;
	long b = n;				//b��ʣ�����
	double res = 1.0;
	if (b < 0)					//����С��0��������ת���ɴ���0����ʽ
	{
		x = 1 / x;				//x^(-n)=(1/x)^n
		b = -b;				
	}
	while (b > 0)		
	{
		if ((b & 1) == 1)res *= x;			//ʣ�����Ϊ����ʱ���������һ��x����res��
														//����x^n=x^0��res;      x^n�Ƕ�ƽ����һ�Σ�����res����
		x *= x;			//ִ��x=x^2
		b >>= 1;		//b����һλ����ʣ���������2
	}
	return res;

}

bool Solution::verifyPostorder(vector<int>& postorder)
{
	//������������Ҹ�
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
		int c = (unsigned int)(a & b) << 1;	// c = ��λ
		a = a ^ b;						// a = �ǽ�λ��
		b = c;							// b = ��λ
	}
	return a;
}
