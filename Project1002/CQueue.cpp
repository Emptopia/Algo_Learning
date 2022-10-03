#include "CQueue.h"

CQueue::CQueue()
{
	this->st1 = {};
	this->st2 = {};
}


void CQueue::appendTail(int value)
{
	this->st1.push(value);
}


int CQueue::deleteHead()
{
	//��Ա����ͬʱ������2��ջ
	if (st1.empty() && st2.empty())			//2ջ��û�г�Ա���򷵻�-1
		return -1;
	int res = 0;
	if (!st2.empty())					//st2��st1�ķ�ת�����st2û�г���ջ��������ȳ�ջ
	{
		res = st2.top();
		st2.pop();
		return res;
	}
	else {
		while (!st1.empty())			//st2���û�г�Ա����st1��ת��st2
		{
			st2.push(st1.top());
			st1.pop();
		}
		res = st2.top();					//st2��ջ
		st2.pop();
		return res;
	}
}

