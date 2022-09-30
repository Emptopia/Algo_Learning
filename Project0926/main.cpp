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

void test04()
{
	Solution sln;
	int nums = 5;
	vector<vector<int>>res = sln.generate(nums);
	sln.TTprint(res);
}

void test05()
{
	Solution sln;
	int nums = 9;
	vector<int>res = sln.getRow(nums);
	sln.Tprint(res);
}

void test06()
{
	Solution sln;
	vector<int>nums = { 3, 4, 5, 1, 2 };
	cout << sln.findMin(nums) << endl;
		//输出：1
		//解释：原数组为[1, 2, 3, 4, 5] ，旋转 3 次得到输入数组。
}

void test07()
{
	Solution sln;
	string s = "Let's take LeetCode contest";
	string res = sln.reverseWords(s);
	cout << res << endl;
}

void test08()
{
	Solution sln;
	vector<int>nums = { 0,0,1,1,1,2,2,3,3,4 };
	int res = sln.removeDuplicates(nums);
	cout << res << endl;
	sln.Tprint(nums);
}

void test09()
{
	Solution sln;
	vector<int>nums = { 0,1,0,3,12 };
	sln.moveZeroes(nums);
	sln.Tprint(nums);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	test09();
	system("pause");
	return 0;


}