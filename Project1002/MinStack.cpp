#include "MinStack.h"

MinStack::MinStack() {
	st = {};
	minst = {};				//��һ����Сջ�洢��Сֵ
}

void MinStack::push(int x) {
	st.push(x);
	if (minst.empty())
		minst.push(x);
	else if(minst.top() >= x)
	{
		minst.push(x);					//��Сջtop������С����push
	}
}

void MinStack::pop() {
	if (st.top() == minst.top())			//popʱ�Ƚ��Ƿ����Сֵ��ȣ�����������СջҲpop���������һ���Ƕ�ӦԪ�أ�
		minst.pop();
	st.pop();
	
}

int MinStack::top() {
	return st.top();
}

int MinStack::min() {
	return minst.top();
}