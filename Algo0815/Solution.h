#pragma once
#include<iostream>
using namespace std;
#include<unordered_map>
#include<map>
#include<string>
class Solution
{
public:

	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	int getLength(ListNode* head);


	void printUmap(unordered_map<int, int>m);
	void printLinkList(ListNode* numberList);

	int strStr(string haystack, string needle);
	string countAndSay(int n);
	string longestCommonPrefix(vector<string>& strs);
	void deleteNode(ListNode* node);
	ListNode* removeNthFromEnd(ListNode* head, int n);

};

