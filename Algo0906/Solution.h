#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<unordered_map>
class Solution
{
private:
    unordered_map<char, int>symbolValues =
    {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };

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

    int countPrimes(int n);

    bool isPowerOfThree(int n);


    int romanToInt(string s);
};



