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
	//成员不会同时出现在2个栈
	if (st1.empty() && st2.empty())			//2栈都没有成员，则返回-1
		return -1;
	int res = 0;
	if (!st2.empty())					//st2是st1的反转，如果st2没有出完栈，则会优先出栈
	{
		res = st2.top();
		st2.pop();
		return res;
	}
	else {
		while (!st1.empty())			//st2如果没有成员，则将st1反转给st2
		{
			st2.push(st1.top());
			st1.pop();
		}
		res = st2.top();					//st2出栈
		st2.pop();
		return res;
	}
}

