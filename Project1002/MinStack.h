#pragma once
using namespace std;
#include<iostream>
#include<stack>

//2��ջ�γ�1�����Զ�min����Сջ
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

