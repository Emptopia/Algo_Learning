#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<string>
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
	
};

class CQueue {
public:
    CQueue() {    }
	void inToOut()
	{
		while (!inStack.empty())
		{
			outStack.push(inStack.top());
			inStack.pop();
		}
	}
    void appendTail(int value) {
		inStack.push(value);
    }
    int deleteHead() {
		if (outStack.empty())
		{
			if (inStack.empty())return -1;
			inToOut();
		}
		int value = outStack.top();
		outStack.pop();
		return value;
    }
	stack<int>inStack;
	stack<int>outStack;
};

class Solution
{
public:
	bool hasPathSum(TreeNode* root, int targetSum);
	bool isPalindrome(string s);
	ListNode* reverseList(ListNode* head);
	bool canConstruct(string ransomNote, string magazine);
	string addBinary(string a, string b);
};

