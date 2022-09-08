#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
class Solution
{
public:
    vector<int>origin;
    vector<int>current;
    int n;
    Solution() {}

    void printVector(vector<int>& nums);
    void printsVector(vector<string>& nums);

    Solution(vector<int>& nums);

    vector<int> reset();

    vector<int> shuffle();

    vector<string> fizzBuzz(int n);

};



