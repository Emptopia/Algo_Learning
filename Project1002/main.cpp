using namespace std;
#include<iostream>
#include<stack>
#include"Solution.h"
#include"CQueue.h"
#include"MinStack.h"
#include"ListNode.h"
#include<vector>
#include"Node.h"

void test01()
{
	CQueue* obj = new CQueue();
	obj->appendTail(3);
	int res = obj->deleteHead();
	cout << res << endl;
}

void test02()
{
	MinStack* mst = new MinStack();
	mst->push(1);
	mst->push(-1);
	int res = mst->min();
	cout << res << endl;
}

void test03()
{
	//链表使用复习
	
	//定义一个初始为空的链表
	//ListNode* head = nullptr;				//可以在下面直接一起构造

	// Create first node with 12.5
	ListNode* head = new ListNode(12); // 构造函数，创建val = 12.5, next = NULL的结点
	//head->next = nullptr; // 已经指向NULL了
	
	// Create second node with 13.5
	ListNode* secondPtr = new ListNode(13);
	//secondPtr->next = nullptr; // 已经指向NULL了

	head->next = secondPtr; // 第一个结点next = 第二个结点

	// Print the list
	cout << "First item is " << head->val << endl;
	cout << "Second item is " << head->next->val << endl;



}
void test04()
{
	ListNode* head = new ListNode(1);
	ListNode* secondPtr = new ListNode(3);
	ListNode* thirdPtr = new ListNode(2);
	head->next = secondPtr;
	secondPtr->next = thirdPtr;
	Solution sln;
	vector<int>res = sln.reversePrint(head);
	sln.Tprint(res);

}

void test05()
{
	ListNode* head = new ListNode(1);
	ListNode* secondPtr = new ListNode(2);
	ListNode* thirdPtr = new ListNode(3);
	head->next = secondPtr;
	secondPtr->next = thirdPtr;
	Solution sln;
	ListNode* res = sln.reverseList(head);
	cout << res->val << endl;
	sln.ListPrint(res);

}

void test06()
{
	Node* head = new Node(1);
	Node* secondPtr = new Node(2);
	head->next = secondPtr;
	head->random = secondPtr;
	secondPtr->random = secondPtr;
	Solution sln;
	sln.copyRandomList(head);
	//懒得验证了

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}