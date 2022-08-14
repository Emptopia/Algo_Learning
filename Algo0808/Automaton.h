#pragma once
#include<iostream>
using namespace std;
#include<unordered_map>

class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table = 
    {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c);
public:
    int sign = 1;
    long long ans = 0;
    void get(char c);
};

