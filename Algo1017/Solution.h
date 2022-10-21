#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution
{
public:
	void Lprint(ListNode* head);
	template<typename T>
	void Tprint(vector<T>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	template<typename T>
	void TTprint(vector<vector<T>>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			for (auto itt = it->begin(); itt != it->end(); itt++)
			{
				cout << *itt << " ";
			}
			cout << endl;
		}
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
	vector<int> exchange(vector<int>& nums);
	vector<int> twoSum(vector<int>& nums, int target);
	string reverseWords(string s);
	bool exist(vector<vector<char>>& board, string word);
	int movingCount(int m, int n, int k);
	vector<vector<int>> pathSum(TreeNode* root, int target);
	Node* treeToDoublyList(Node* root);
	int kthLargest(TreeNode* root, int k);

private:
	bool dp1(vector<vector<char>>& board, string& word,int i, int j, int k);
	int dp2(int i, int j, int m, int n, int k, vector<vector<int>>&mark);
	void dp3(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& temp, int sum);
	void recur4(Node* cur);
	Node* pre;
	Node* head;
	void recur5(TreeNode* root);
	vector<int>nums;
};

