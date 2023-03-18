#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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
	void Lprint(ListNode* head)
	{
		if (head == nullptr)
		{
			cout << endl;
			return;
		}
		cout << head->val << " ";
		Lprint(head->next);
	}

	int removeDuplicates(vector<int>& nums);
	bool isValid(string s);
	bool isPalindrome(int x);
	int removeElement(vector<int>& nums, int val);
	int searchInsert(vector<int>& nums, int target);
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	string longestCommonPrefix(vector<string>& strs);
	int romanToInt(string s);
	void moveZeroes(vector<int>& nums);
	int climbStairs(int n);
	int maxProfit(vector<int>& prices);
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	vector<int> plusOne(vector<int>& digits);
	int maxDepth(TreeNode* root);
	bool hasCycle(ListNode* head);
	int search(vector<int>& nums, int target);
	int lengthOfLastWord(string s);
	int findRepeatNumber(vector<int>& nums);
	bool isSymmetric(TreeNode* root);

private:
	bool check1(TreeNode* t1, TreeNode* t2);
};

