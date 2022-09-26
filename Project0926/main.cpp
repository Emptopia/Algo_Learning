#include<iostream>
using namespace std;
#include<vector>
#include"Solution.h"
void test01()
{
	Solution sln;
	vector<int>nums = { 0,1,2,2,3,0,4,2 };
	int val = 2;
	int res = sln.removeElement(nums, 2);
	cout << "res = " << res << endl;
	sln.Tprint(nums);
}

void test02()
{
	Solution sln;
	vector<int>nums = { 1,1,0,1,1,1 };
	int res = sln.findMaxConsecutiveOnes(nums);
	cout << "res = " << res << endl;

}

void test03()
{
	Solution sln;
	vector<int>nums = { 1,4,4 };
	int target = 4;
	int res = sln.minSubArrayLen(target, nums);
	cout << res << endl;
	vector<int>nums2 = { 1, 1, 1, 1, 1, 1, 1, 1 };
	int target2 = 11;
	int res2 = sln.minSubArrayLen(target2, nums2);
	cout << res2 << endl;




}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;


}