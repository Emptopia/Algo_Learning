#include<vector>
#include<list>
#include<iostream>
using namespace std;
#include"Solution.h"


void test01()
{
    Solution sln;

    vector<int>nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    cout << "ԭʼ���飺{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }" << endl;
    int length = sln.removeDuplicates(nums);
    cout << "��������鳤�ȣ�" << length << endl;
    cout << "���������Ϊ��";
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void test02()
{
    Solution sln;
    vector<int> prices = { 3,4,5,2,7 };
    cout << "�������Ϊ��" << sln.maxProfit(prices) << endl;
}


int main()
{
	//test01();
    test02();




	system("pause");
	return 0;
}