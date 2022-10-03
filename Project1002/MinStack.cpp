#include "MinStack.h"

MinStack::MinStack() {
	st = {};
	minst = {};				//用一个最小栈存储最小值
}

void MinStack::push(int x) {
	st.push(x);
	if (minst.empty())
		minst.push(x);
	else if(minst.top() >= x)
	{
		minst.push(x);					//最小栈top不是最小，则push
	}
}

void MinStack::pop() {
	if (st.top() == minst.top())			//pop时比较是否和最小值相等，如果相等则最小栈也pop，（相等则一定是对应元素）
		minst.pop();
	st.pop();
	
}

int MinStack::top() {
	return st.top();
}

int MinStack::min() {
	return minst.top();
}