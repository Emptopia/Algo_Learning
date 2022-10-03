#pragma once
using namespace std;
#include<iostream>
#include<stack>

//2个栈形成1个可以读min的最小栈
class MinStack
{
public:
    stack<int>st;
    stack<int>minst;
    
    MinStack();

    void push(int x);
    void pop();
    int top();
    int min();
};

