#pragma once
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
    vector<int>origin;
    vector<int>current;
    int n;

    void printVector(vector<int>& nums);

    Solution(vector<int>& nums);

    vector<int> reset();

    vector<int> shuffle();

};



