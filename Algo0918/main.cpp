#include<iostream>
using namespace std;
#include "Solution.h"
#include<vector>

void test01()
{
	Solution sln;
	vector<int>nums = { 1, 7, 3, 6, 5, 6 };
	int res = sln.pivotIndex(nums);
	cout << res << endl;
}

void test02()
{
	Solution sln;
	vector<int>nums = { 1,3,5,6 };
	int target = 5;
	int res = sln.searchInsert(nums, target);
	cout << res << endl;

}

void test03()
{
	Solution sln;
	vector<vector<int>>intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
	vector<vector<int>>res = sln.merge(intervals);
	sln.VVprint(res);

}

void test04()
{
	Solution sln;
	//vector<vector<int>>matrix = 
	//{ { 5, 1, 9,11 },
	//{ 2, 4, 8,10 },
	//{ 13, 3, 6, 7 },
	//{ 15,14,12,16 } };
	vector<vector<int>>matrix =
	{ {1, 2}, { 3, 4 }};
	//vector<vector<int>>matrix =
	//{
	//	{1,2,3},
	//	 {4,5,6},
	//	{7,8,9}
	//};
	sln.VVprint(matrix);
	sln.rotate(matrix);
	sln.VVprint(matrix);
}

void test05()
{
	Solution sln;
	vector<vector<int>>matrix =
	{
		{ 0,1,2,0 },
		{ 3,4,5,2 },
		{ 1,3,1,5 }
	};
	sln.setZeroes(matrix);
	sln.VVprint(matrix);
}

void test06()
{
	Solution sln;
	//vector<vector<int>>mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	vector<vector<int>>mat = { {2,3} };
	vector<int>res = sln.findDiagonalOrder(mat);
	sln.Vprint(res);
}

void test07()
{
	Solution sln;
	vector<string>strs = { "flower","flow","flight" };
	string res = sln.longestCommonPrefix(strs);
	cout << res << endl;
}

void test08()
{
	Solution sln;
	string s = "babad";
	string res = sln.longestPalindrome(s);
	cout << res << endl;
}

void test09()
{
	Solution sln;
	string s = " the sky is     blue ";
	string res = sln.reverseWords(s);
	cout << res << endl;

}

void test10()
{
	Solution sln;
	string haystack = "hello";
	string needle = "ll";
	int res = sln.strStr(haystack, needle);
	cout << res << endl;
}

void vs01()
{
	Solution sln;
	vector<int>temperatureA = { 5, 10, 16, -6, 15, 11, 3 };
	vector<int>temperatureB = { 16,22,23,23,25,3,-16 };

	int res = sln.temperatureTrend(temperatureA, temperatureB);
	cout << res << endl;


}

void vs02()
{
	Solution sln;
	vector<vector<int>>path = { {0, 1}, { 0,3 }, { 1,3 }, { 2,0 }, { 2,3 } };		//3
	vector<vector<int>>path2 = { {0,3},{1,0},{1,3},{2,0},{3,0},{3,2} };			//-1

	int res1 = sln.transportationHub(path);
	int res2 = sln.transportationHub(path2);
	cout << res1 << endl;
	cout << res2<< endl;


}

void vs03()
{
	Solution sln;
	int num = 4;
	vector<string>plate = { "..E.", ".EOW", "..W." };
	vector<vector<int>>res = sln.ballGame(num, plate);
	sln.VVprint(res);

	int num2 = 5;
	vector<string>plate2 = { ".....","..E..",".WO..","....." };
	vector<vector<int>>res2 = sln.ballGame(num2, plate2);
	sln.VVprint(res2);

	int num3 = 3;
	vector<string>plate3 = { ".....","....O","....O","....." };
	vector<vector<int>>res3 = sln.ballGame(num3, plate3);
	sln.VVprint(res3);

	int num4 = 1;
	cout << "res4" << endl;
	vector<string>plate4 = { ".....", "..O..", "....." };
	vector<vector<int>>res4 = sln.ballGame(num4, plate4);
	sln.VVprint(res4);

	int num5 = 41;
	cout << "res5" << endl;
	vector<string>plate5 = { "E...W..WW", ".E...O...", "...WO...W", "..OWW.O..", ".W.WO.W.E", "O..O.W...", ".OO...W..", "..EW.WEE." };
	vector<vector<int>>res5 = sln.ballGame(num5, plate5);
	sln.VVprint(res5);


}
void vs04()
{
	Solution sln;

}

void vs05()
{
	Solution sln;

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
	//test09();
	//test10();
	//vs01();
	//vs02();
	vs03();
	//vs04();
	//vs05();

	system("pause");
	return 0;
}