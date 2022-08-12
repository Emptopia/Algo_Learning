using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include"Solution.h"

void test01()
{
	Solution sln;
	vector<vector<int>> matrix =
	  { {5, 1, 9, 11}
	, {2, 4, 8, 10}
	, {13, 3, 6, 7}
	, {15, 14, 12, 16} };
	sln.printMatrix(matrix);

	sln.rotate(matrix);
	sln.printMatrix(matrix);

}

void test02()
{
	Solution sln;

	vector<char>s = {'h', 'e', 'l', 'l', 'o'};
	sln.reverseString(s);
	sln.printVector(s);
}

void test03()
{
	Solution sln;
	int x = 120;
	cout << sln.reverse(x) << endl;
}

void test04()
{
	Solution sln;
	string s = "loveleetcode";
	cout << sln.firstUniqChar(s) << endl;
}

void test05()
{
	Solution sln;
	string s = "anagram";
	string t = "nagaram";
	bool res = sln.isAnagram(s, t);
	if (res == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	system("pause");
	return 0;
}