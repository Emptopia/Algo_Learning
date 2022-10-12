#include "Solution.h"

bool Solution::findNumberIn2DArray(vector<vector<int>>&matrix, int target)
{
	if (matrix.empty())
		return false;
	int row = matrix.size();
	int column = matrix[0].size();
	//1������
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < column; j++)
	//	{
	//		if (matrix[i][j] == target)
	//			return true;
	//	}
	//}
	//return false;

	//2�����������					//��������������ʱ��Ц��
	int i = row - 1;
	int j = 0;
	while (i >= 0 && j < column)
	{
		if (matrix[i][j] > target)
			i--;
		else if (matrix[i][j] < target)
			j++;
		else
			return true;
	}
	return false;
}

int Solution::minArray(vector<int>& numbers)
{
	//����
	//for (int i = 0; i < numbers.size()-1; i++)
	//{
	//	if (numbers[i] > numbers[i + 1])
	//		return numbers[i + 1];
	//}
	//return numbers[0];

	//����
	int left = 0;
	int right = numbers.size() - 1;
	while (left < right)
	{
		int m = (left + right) / 2;
		if (numbers[m] > numbers[right])
			left = m + 1;
		else if (numbers[m] < numbers[right])
			right = m;
		else
			right--;
	}
	return numbers[left];
}

char Solution::firstUniqChar(string s)
{
	map<char, int>m;
	for (char i : s)
	{
		m[i]++;
	}
	for (char i : s)
	{
		if (m[i] == 1)
			return i;
	}
	return ' ';
}

//void Solution::helper1(TreeNode* root, vector<int>&res)
//{
//	res.push_back(root->val);
//	if (root->left != nullptr)
//		helper1(root->left,res);
//	if (root->right != nullptr)
//		helper1(root->right,res);
//}

vector<int> Solution::levelOrder(TreeNode* root)
{
	//			�Լ��ĵݹ飬ʵ��������Ҵ�ӡ���֣�
	//if (root == nullptr)
	//	return {};
	//vector<int>res;
	//helper1(root, res);
	//return res;

	//BFS�����������   �����ӡ
	//����
	if (root == nullptr)
		return {};
	vector<int>res;
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		res.push_back(temp->val);
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	return res;
}

vector<vector<int>> Solution::levelOrder2(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == nullptr)
		return {};
	queue<TreeNode*>q;
	q.push(root);
	vector<int>tmp;
	while (!q.empty())
	{
		for (int i = q.size(); i > 0; i--)
		{
			TreeNode* temp = q.front();
			q.pop();
			tmp.push_back(temp->val);
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		res.push_back(tmp);
		tmp = {};
	}
	return res;

}

vector<vector<int>> Solution::levelOrder3(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == nullptr)
		return {};
	queue<TreeNode*>q;
	q.push(root);
	vector<int>tmp;
	while (!q.empty())
	{
		for (int i = q.size(); i > 0; i--)
		{
			TreeNode* temp = q.front();
			q.pop();
			tmp.push_back(temp->val);
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		if (res.size() % 2 == 1)
			reverse(tmp.begin(),tmp.end());
		res.push_back(tmp);
		tmp = {};
	}
	return res;

}

bool Solution::recur(TreeNode* A, TreeNode* B)			
{
	//�ڲ����		�����������Ƿ����B
	//BΪ�����������������true
	//AΪ�ջ�ABֵ���ȣ�����false
	//ABֵ��ȣ����������AB��������
	if (B == nullptr)		//B����������ʱ������Ҫ�Ƚ�A
		return true;
	if (A == nullptr || A->val != B->val)
		return false;
	return recur(A->left, B->left) && recur(A->right, B->right);
}

bool Solution::isSubStructure(TreeNode* A, TreeNode* B)			
{
	//������
	//ABΪ����false
	//�ڲ����Ϊtrueʱ������true
	//A����������B������Ϊtrueʱ������true
	return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
}

void Solution::recur2(TreeNode* Node)
{
	if (Node == nullptr)
		return;
	TreeNode* temp;
	if (Node->left != nullptr && Node->right != nullptr)
	{
		temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}
	else if (Node->left != nullptr)
	{
		Node->right = Node->left;
		Node->left = nullptr;
	}
	else if (Node->right != nullptr)
	{
		Node->left = Node->right;
		Node->right = nullptr;
	}
	recur2(Node->left);
	recur2(Node->right);
}

TreeNode* Solution::mirrorTree(TreeNode* root)
{
	//�ٷ��ⷨ
	//if (root == nullptr) return nullptr;				//�����������ָ����ֱ�ӷ���
	//TreeNode* tmp = root->left;						//temp
	//root->left = mirrorTree(root->right);			//���߽�����ֵ��������
	//root->right = mirrorTree(tmp);
	//return root;

	recur2(root);
	return root;

}

bool Solution::recur3(TreeNode* A, TreeNode* B)
{
	if (A == nullptr && B == nullptr)
		return true;
	if (A == nullptr || B == nullptr || A->val != B->val)
		return false;
	return recur3(A->left, B->right)&& recur3(A->right, B->left);
}


bool Solution::isSymmetric(TreeNode* root)
{
	if (root == nullptr)
		return true;
	return recur3(root->left, root->right);
}
