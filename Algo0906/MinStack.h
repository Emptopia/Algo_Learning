#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class MinStack
{
public:
    stack<int>values;
    stack<int>minStack;
    MinStack();

    void push(int val);

    void pop();

    int top();

    int getMin();

};

