#include "MinStack.h"

MinStack::MinStack()
{
	minStack.push(INT_MAX);
}

void MinStack::push(int val) 
{
	values.push(val);
	minStack.push(min(minStack.top(), val));
}

void MinStack::pop()
{
	values.pop();
	minStack.pop();
}

int MinStack::top()
{
	return values.top();
}

int MinStack::getMin()
{
	return minStack.top();

	
}