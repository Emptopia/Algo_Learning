#include<vector>
#include<list>
#include<iostream>
using namespace std;
#include"Solution.h"


int Solution::removeDuplicates(vector<int>& nums)
{
    if (nums.empty())
        return 0; // ��������ж�
    int left = 0;
    for (int right = 1; right < (nums.size()); right++) {
        if (nums[left] != nums[right])
        { // ���ֺͺ�һ������ͬ
            nums[++left] = nums[right];
            //left = 0 ������һ���ǲ��ظ��ģ�����ֱ�� ++left
        }
    }
    return ++left; //������left�Ǵ�0��ʼ�ģ����Է���left+ 1
}

