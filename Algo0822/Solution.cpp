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