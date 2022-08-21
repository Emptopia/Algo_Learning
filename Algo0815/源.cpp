#include<iostream>
using namespace std;
#include"Solution.h"
#include<unordered_map>
#include<map>




void test01()
{
	Solution sln;
	string haystack = "hello";
	string needle = "ll";
	cout << sln.strStr(haystack, needle) << endl;
}

void test02()
{
	Solution sln;
	cout << sln.countAndSay(1) << endl;
	cout << sln.countAndSay(2) << endl;
	cout << sln.countAndSay(3) << endl;
	cout << sln.countAndSay(4) << endl;



}

void test03()
{
	Solution sln;
	vector<string>strs = { "flower", "flow", "flight" };
	cout << sln.longestCommonPrefix(strs) << endl;
}

void test04()
{
	Solution sln;


	Solution::ListNode* L = new Solution::ListNode(4);
	Solution::ListNode* l1 = new Solution::ListNode(5);
	Solution::ListNode* l2 = new Solution::ListNode(1);
	Solution::ListNode* l3 = new Solution::ListNode(9);
	L->next = l1;
	l1->next = l2;
	l2->next = l3;
	sln.deleteNode(l1);
	sln.printLinkList(L);

}

void test05()
{
	Solution sln;
	Solution::ListNode* FivePtr = new Solution::ListNode(5);
	Solution::ListNode* FourPtr = new Solution::ListNode(4, FivePtr);
	Solution::ListNode* ThreePtr = new Solution::ListNode(3, FourPtr);
	Solution::ListNode* TwoPtr = new Solution::ListNode(2, ThreePtr);
	Solution::ListNode* OnePtr = new Solution::ListNode(1, TwoPtr);

	//Solution::ListNode* OnePtr = new Solution::ListNode(1);

	//Solution::ListNode* TwoPtr = new Solution::ListNode(2);
	//Solution::ListNode* OnePtr = new Solution::ListNode(1, TwoPtr);

	sln.printLinkList(sln.removeNthFromEnd(OnePtr, 3));

}

void test06()
{
	Solution sln;
	Solution::ListNode* FivePtr = new Solution::ListNode(5);
	Solution::ListNode* FourPtr = new Solution::ListNode(4, FivePtr);
	Solution::ListNode* ThreePtr = new Solution::ListNode(3, FourPtr);
	Solution::ListNode* TwoPtr = new Solution::ListNode(2, ThreePtr);
	Solution::ListNode* OnePtr = new Solution::ListNode(1, TwoPtr);
	
	sln.printLinkList(sln.reverseList(OnePtr));

}

void test07()
{
	Solution sln;
	Solution::ListNode* ThirdPtr = new Solution::ListNode(4);
	Solution::ListNode* SecondPtr = new Solution::ListNode(2,ThirdPtr);
	Solution::ListNode* FirstPtr = new Solution::ListNode(1, SecondPtr);

	Solution::ListNode* ThirdPtr2 = new Solution::ListNode(4);
	Solution::ListNode* SecondPtr2 = new Solution::ListNode(3, ThirdPtr2);
	Solution::ListNode* FirstPtr2 = new Solution::ListNode(1, SecondPtr2);

	Solution::ListNode* res = sln.mergeTwoLists(FirstPtr, FirstPtr2);
	sln.printLinkList(res);


}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
	system("pause");
}