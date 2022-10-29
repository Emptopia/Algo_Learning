#include "Solution.h"

void Solution::quickSort(vector<int>&arr, int l, int r)
{
	//快速排序基础算法
	if (l >= r)return;
	int i = l, j = r;
	while (i < j)
	{
		while (i < j && arr[j] >= arr[l])j--;
		while (i < j && arr[i] <= arr[l])i++;
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[l]);
	//递归
	quickSort(arr, l, i - 1);
	quickSort(arr, i + 1, r);

}

vector<int> Solution::getLeastNumbers(vector<int>& arr, int k)
{
	quickSort(arr, 0, arr.size() - 1);
	vector<int>res;
	res.assign(arr.begin(), arr.begin() + k);
	return res;



	//vector<int>res;
	//sort(arr.begin(), arr.end());
	//for (int i = 0; i < k; i++)
	//{
	//	res.push_back(arr[i]);
	//}
	//return res;

}


int Solution::maxDepth(TreeNode * root)
{
	//dfs
	if (root == nullptr)return 0;

	return max(maxDepth(root->left), maxDepth(root->right))+1;
}

int Solution::dfs1(TreeNode* Node)
{
	if (this->isBa == false)return 0;
	if (Node == nullptr)return 0;
	int d1 = dfs1(Node->left);
	int d2 = dfs1(Node->right);
	cout << "d1 = " << d1 << " d2 = " << d2 << endl;
	if (d1 - d2 > 1 || d2 - d1 > 1)
	{
		this->isBa = false;
	}
	return max(d1, d2) + 1;

}

bool Solution::isBalanced(TreeNode* root)
{
	dfs1(root);
	if (this->isBa == false)
	{
		return false;
	}
	else
	{
		return true;
	}

}