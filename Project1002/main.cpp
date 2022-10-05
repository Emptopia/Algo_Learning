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
	//����ʹ�ø�ϰ
	
	//����һ����ʼΪ�յ�����
	//ListNode* head = nullptr;				//����������ֱ��һ����

	// Create first node with 12.5
	ListNode* head = new ListNode(12); // ���캯��������val = 12.5, next = NULL�Ľ��
	//head->next = nullptr; // �Ѿ�ָ��NULL��
	
	// Create second node with 13.5
	ListNode* secondPtr = new ListNode(13);
	//secondPtr->next = nullptr; // �Ѿ�ָ��NULL��

	head->next = secondPtr; // ��һ�����next = �ڶ������

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
	//������֤��

}

void test07()
{
	Solution sln;
	string s = "We are happy.";
	string res = sln.replaceSpace(s);
	cout << res << endl;
}

void test08()
{
	Solution sln;
	string s = "abcdefg";
	int k = 2;
	string res = sln.reverseLeftWords(s, k);
	cout << res << endl;
}

void test09()
{
	Solution sln;
	vector<int>nums = { 2, 3, 1, 0, 2, 5, 3 };
	int res = sln.findRepeatNumber(nums);
	cout << res << endl;
}

void test10()
{

	Solution sln;
	vector<int>nums = { 5,7,7,8,8,10 };
	int target = 8;
	int res = sln.search(nums, target);
	cout << res << endl;
}

void test11()
{
	Solution sln;
	vector<int>nums = { 0,1,2,3,4,5,6,7,9 };
	int res = sln.missingNumber(nums);
	cout << res << endl;

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	test11();

	system("pause");
	return 0;
}