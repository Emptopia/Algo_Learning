#include "Solution.h"

void Solution::printLinkList(ListNode* list)
{
	ListNode* ptr = list;
	while (ptr != nullptr)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

ListNode* Solution::LinkList(vector<int> n)
{
	ListNode* prev = new ListNode(-1);
	ListNode* ptr = prev;
	for (int i = 0; i < n.size(); i++)
	{
		ListNode* nex = new ListNode(n[i]);
		ptr->next = nex;
		ptr = ptr->next;
	}
	ListNode* ans = prev->next;
	delete prev;
	return ans;
}

bool Solution::isPalindrome(ListNode* head)			//消耗过大，不建议用
{
	vector<int>nums;
	ListNode* ptr = head;
	while (ptr != nullptr)
	{
		nums.push_back(ptr->val);
		ptr = ptr->next;
	}
	reverse(nums.begin(), nums.end());
	ptr = head;
	for (int i = 0; i < nums.size(); i++)
	{
		if (ptr->val != nums[i])
			return false;
		ptr = ptr->next;
	}
	return true;
}

bool Solution::hasCycle(ListNode* head)
{
	if (head == nullptr)
		return false;

	ListNode* dummy = new ListNode(-1,head);
	ListNode* left = dummy;
	ListNode* right = head;
	while (right != nullptr)
	{
		if (right->next == right)
			return true;
		while (left != right)
		{
			if (right->next == left)
			{
				return true;
			}
			left = left->next;
		}
		left = dummy;
		right = right->next;
	}

	return false;

}

//int Solution::maxDepth(TreeNode* root)
//{
//	if (root == nullptr) 
//		return 0;
//	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//}

int Solution::maxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	queue<TreeNode*>Q;
	Q.push(root);
	int ans = 0;
	while (!Q.empty())
	{
		int sz = Q.size();
		while (sz > 0)
		{
			TreeNode* node = Q.front();
			Q.pop();
			if (node->left)
				Q.push(node->left);
			if (node->right)
				Q.push(node->right);
			sz -= 1;
		}
		ans += 1;
	}
	return ans;
}

void Solution::traversal(TreeNode* root) {
	if (root == NULL) return;
	traversal(root->left);
	vec.push_back(root->val); // 将二叉搜索树转换为有序数组
	traversal(root->right);
}



bool Solution::isValidBST(TreeNode* root)
{
	vec.clear(); // 不加这句在leetcode上也可以过，但最好加上
	traversal(root);
	for (int i = 1; i < vec.size(); i++) {
		// 注意要小于等于，搜索树里不能有相同元素
		if (vec[i] <= vec[i - 1]) return false;
	}
	return true;
}

bool Solution::check(TreeNode* u, TreeNode* v) {
	queue <TreeNode*> q;
	q.push(u); q.push(v);
	while (!q.empty()) {
		u = q.front(); q.pop();
		v = q.front(); q.pop();
		if (!u && !v) continue;
		if ((!u || !v) || (u->val != v->val)) return false;

		q.push(u->left);
		q.push(v->right);

		q.push(u->right);
		q.push(v->left);
	}
	return true;
}

bool Solution::isSymmetric(TreeNode* root) {
	return check(root, root);
}


vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
	vector <vector <int>> ret;
	if (!root) {
		return ret;
	}

	queue <TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int currentLevelSize = q.size();
		ret.push_back(vector <int>());
		for (int i = 1; i <= currentLevelSize; ++i) {
			auto node = q.front(); q.pop();
			ret.back().push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
	}

	return ret;

}

void Solution::printVector(vector<vector<int>>v)
{
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator iit = it->begin(); iit != it->end(); iit++)
		{
			cout << *iit;
		}
		cout << endl;
	}
}
