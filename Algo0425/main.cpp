#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>


void t01()
{
	Solution sln;
	vector<int>arr = { 3, 2, 1 };
	int  k = 2;
	vector<int>res = sln.getLeastNumbers(arr, k);
	sln.Tprint(res);
}

int main()
{
	t01();
}