#pragma once
using namespace std;
#include<iostream>
#include<stack>
#include"Solution.h"

//2个栈形成1个队列
class CQueue {
public:
    stack<int>st1;
    stack<int>st2;

    CQueue();


    void appendTail(int value);


    int deleteHead();

};
