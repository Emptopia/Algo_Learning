#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<string>

class MyStack {
public:
    MyStack() {
        q1 = {}; q2 = {};
    }

    void push(int x) {
        if (q1.empty())q1.push(x);
        else
        {
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            queue<int>temp = q1;
            q1 = q2;
            q2 = temp;
        }
    }

    int pop() {
        int tmp = q1.front();
        q1.pop();
        return tmp;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        if (q1.empty())return true;
        else return false;
    }
    queue<int>q1;
    queue<int>q2;
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution
{
public:
    template<typename T>
    void Tprint(vector<T>v)
    {
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";

        }
        cout << endl;
    }
    void ListPrint(ListNode* head);


    int lengthOfLastWord(string s);
    vector<int> twoSum(vector<int>& nums, int target);
    ListNode* reverseList(ListNode* head);
};

