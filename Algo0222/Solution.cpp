#include "Solution.h"
#include<unordered_map>
void Solution::ListPrint(ListNode* head)
{
	cout << head->val << " ";
	if (head->next != nullptr)ListPrint(head->next);
}
int Solution::lengthOfLastWord(string s)
{
	int count = 0;
	int p = s.size() - 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			p = i;
			break;
		}
	}
	for (int i = p; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			return p - i;
		}
	}

	return p+1;
}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int>m;
	vector<int>res;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = m.find(target - nums[i]);
		if (it != m.end())
		{
			res.push_back(it->second);
			res.push_back(i);
			break;
		}
		m.insert({ nums[i],i });

	}
	return res;
}

ListNode* Solution::reverseList(ListNode* head)
{
	ListNode* cur = nullptr;
	ListNode* pre = head;
	while (pre != nullptr)
	{
		ListNode* t = pre->next;
		pre->next = cur;
		cur = pre;
		pre = t;
	}
	return cur;
}
