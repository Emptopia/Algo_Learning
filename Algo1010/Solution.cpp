#include "Solution.h"

bool Solution::findNumberIn2DArray(vector<vector<int>>&matrix, int target)
{
	if (matrix.empty())
		return false;
	int row = matrix.size();
	int column = matrix[0].size();
	//1、暴力
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < column; j++)
	//	{
	//		if (matrix[i][j] == target)
	//			return true;
	//	}
	//}
	//return false;

	//2、按规则遍历					//力扣跑起来更耗时，笑死
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
	//暴力
	//for (int i = 0; i < numbers.size()-1; i++)
	//{
	//	if (numbers[i] > numbers[i + 1])
	//		return numbers[i + 1];
	//}
	//return numbers[0];

	//二分
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
	//			自己的递归，实现先左后右打印（怪）
	//if (root == nullptr)
	//	return {};
	//vector<int>res;
	//helper1(root, res);
	//return res;

	//BFS广度优先搜索   按层打印
	//队列
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