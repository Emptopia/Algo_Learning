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