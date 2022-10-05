#pragma once
using namespace std;
#include<iostream>
#include<stack>
#include"Solution.h"
#include"CQueue.h"
#include"MinStack.h"
#include"ListNode.h"
#include<vector>
#include"Node.h"
#include<unordered_map>
#include<set>
class Solution
{
public:
	template<typename T>
	void Tprint(vector<T>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	void ListPrint(ListNode* head)
	{
		ListNode* temp = head;
		while (temp != nullptr)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	vector<int> reversePrint(ListNode* head);
	ListNode* reverseList(ListNode* head);
	Node* copyRandomList(Node* head);
	string replaceSpace(string s);
	string reverseLeftWords(string s, int n);
	int findRepeatNumber(vector<int>& nums);
	int search(vector<int>& nums, int target);
	int missingNumber(vector<int>& nums);

};

