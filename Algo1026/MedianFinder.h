#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<queue>
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder();
  

    void addNum(int num);

    double findMedian();

    priority_queue<int, vector<int>, greater<int>>A;         //从大到小，top为小
    priority_queue<int, vector<int>, less<int>>B;         //从小到大，top为大



};