#include "Solution.h"

void Solution::printUmap(unordered_map<int, int>m)
{
	for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}
}

void Solution::printLinkList(ListNode* numberList)
{
	ListNode* ptr = numberList;
	while (ptr != nullptr)
	{
		cout << ptr->val << " "; // Process node
		ptr = ptr->next; // Move to next node
	}
}

int Solution::strStr(string haystack, string needle)
{
	bool res = true;
	for (int i = 0; i < haystack.size(); i++)
	{
		if (needle[0] == haystack[i])
		{
			for (int j = 0; j < needle.size(); j++)
			{
				res = true;
				if (needle[j] != haystack[i + j])
				{
					res = false;
					break;
				}
			}
			if(res == true)
				return i;
		}
	}
	return -1;
}

string Solution::countAndSay(int n)
{
	string res = "1";
	for (int i = 0; i < n-1; i++)
	{
		int count = 0;
		int num = res[0] - '0';
		string tempRes = "";
		for (int j = 0; j < res.size(); j++)
		{
			if (num == res[j]-'0')
				count++;
			else
			{
				tempRes += (to_string(count) + to_string(num));
				num = res[j] - '0';
				count = 1;
			}
		}
		tempRes += (to_string(count) + to_string(num));
		res = tempRes;
	}
	return res;
}

string Solution::longestCommonPrefix(vector<string>& strs)
{
	string res = "";
	bool same = true;
	for (int i = 0; i < strs[0].size(); i++)
	{
		for (int j = 1; j < strs.size(); j++)
		{
			if (strs[0][i] != strs[j][i])
			{
				same = false;
			}
		}
		if (same == true)
			res += strs[0][i];
		else
			break;
	}
	return res;
}

void Solution::deleteNode(ListNode* node)
{
	node->val = node->next->val;
	node->next = node->next->next;
}

int Solution::getLength(ListNode* head) 
{
	int length = 0;
	while (head) {
		++length;
		head = head->next;
	}
	return length;
}

Solution::ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
	ListNode* dummy = new ListNode(0, head);
	int length = getLength(head);
	ListNode* cur = dummy;
	for (int i = 1; i < length - n + 1; ++i) {
		cur = cur->next;
	}
	cur->next = cur->next->next;
	ListNode* ans = dummy->next;
	delete dummy;
	return ans;
}

Solution::ListNode* Solution::reverseList(ListNode* head)
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

Solution::ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* preHead = new ListNode(-1);

	ListNode* prev = preHead;
	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val < l2->val) {
			prev->next = l1;
			l1 = l1->next;
		}
		else {
			prev->next = l2;
			l2 = l2->next;
		}
		prev = prev->next;
	}
	// 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
	prev->next = l1 == nullptr ? l2 : l1;
	return preHead->next;
}