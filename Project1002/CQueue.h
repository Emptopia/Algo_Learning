#pragma once
using namespace std;
#include<iostream>
#include<stack>
#include"Solution.h"

//2��ջ�γ�1������
class CQueue {
public:
    stack<int>st1;
    stack<int>st2;

    CQueue();


    void appendTail(int value);


    int deleteHead();

};
