#pragma once
using namespace std;
#include<iostream>


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}		//此构造函数用法，ListNode ln(5);     创建一个val=5,next=NULL的链表
	
};