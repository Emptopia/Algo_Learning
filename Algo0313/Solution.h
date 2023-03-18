#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include<stack>
#include<unordered_set>
#include<unordered_map>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
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
	void TreePrint(TreeNode* root)
	{
		if (!root)return;
		cout << root->val << " ";
		TreePrint(root->left);
		TreePrint(root->right);
		cout << endl;
	}

	void ListPrint(ListNode* root)
	{
		while (root)
		{
			cout << root->val << " ";
			root = root->next;
		}
		cout << endl;
	}

	vector<int> inorderTraversal(TreeNode* root);
	TreeNode* invertTree(TreeNode* root);
	int singleNumber(vector<int>& nums);
	int minDepth(TreeNode* root);
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
	int majorityElement(vector<int>& nums);
	int mySqrt(int x);
	void reverseString(vector<char>& s);
	ListNode* getKthFromEnd(ListNode* head, int k);
	string replaceSpace(string s);

private:
	void inorder(TreeNode* root, vector<int>&nums);


};

