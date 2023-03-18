#pragma once
#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
	//һ�����ֲ�����ģ��
	// �������ֵ���Ҳ�������-1
	//1������ұգ������ֹ(l=r+1ʱ��nums������)
	int search1(vector<int>& nums, int target)
	{
		//��Ҫ��
		int l = 0, r = nums.size() - 1;//�ٳ�ֵ
		while (l <= r)//������
		{
			int m = l + (r - l) / 2;//���м�ֵ
			if (nums[m] == target)return m;
			else if (nums[m] < target)l = m + 1;//�����ҽ�
			else r = m - 1;
		}
		return -1;
	}
	//2������ҿ��������ֹ(l=rʱ��nums������)
	int search2(vector<int>& nums, int target)
	{
		//1������ʼ l = 0, r = nums.size() - 1
		//��ô���� while��������l<r���� nums ֻ��һ��Ԫ��ʱ�����޷����� while
		//2���� target ���� nums������Ԫ��ʱ��r = nums.length������һ�����һ����־��
		//������ʼ r = nums.size() - 1��ֻ�� r ������ȡֵ���޷��ж�Ϊ��������ģ�����Ҫ�Ƚ�һ��target �� nums �е����һ��Ԫ�ء�

		int l = 0, r = nums.size();
		while (l < r)//rȡ�������ʲ�ȡ�Ⱥ�
		{
			int m = l + (r - l) / 2;
			if (nums[m] == target)return m;
			else if (nums[m] < target)l = m + 1;
			else r = m;//rȡ�������ҽ粻�ü�1
		}
		return -1;
	}
	//3�����ұգ������ֹ
	int search3(vector<int>& nums, int target)
	{
		int l = -1, r = nums.size()-1;
		while (l < r)//lȡ�������ʲ�ȡ�Ⱥ�
		{
			int m = l + (r - l + 1) / 2;//����Ҫ����ȡ��
			if (nums[m] == target) return m;
			else if (nums[m] < target) l = m;//lȡ��������粻�ü�1
			else r = m - 1;
		}
		return -1;
	}
	//4�����ҿ���������ֹ
	int search4(vector<int>& nums, int target)
	{
		int l = -1, r = nums.size();
		while (l + 1 < r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] == target) return m;
			else if (nums[m] < target)l = m;
			else r = m;
		}
		return -1;
	}

	//�������ֲ���������
	// ������ұ�Ϊ��
	//1�����ڵ���
	int search5(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] < target)l = m + 1;
			else r = m - 1;		//����Ȳ������
		}
		//return (l == nums.size() || nums[l] != target) ? -1 : l;			//����Ѱ�ҵ���ֵʱ
		return l == nums.size() ? -1 : l;			//lԽ��ʱ��nums�����ڴ��ڵ���target����
	}
	//2������
	int search6(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] <= target)l = m + 1;	//����Ȳ���С�ڣ�ѭ��������l����ΪС�ڵ��ڣ�r�Ҳ��Ϊ����
			else r = m - 1;
		}
		return l == nums.size() ? -1 : l;
	}
	//3��С�ڵ���
	int search7(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] <= target)l = m + 1;	//����Ȳ���С�ڣ�ѭ��������l����ΪС�ڵ��ڣ�r�Ҳ��Ϊ����
			else r = m - 1;
		}
		return r;		//��l=0,r�պõ���-1
	}
	//4��С��
	int search8(vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] < target) l = m + 1;
			else r = m - 1;
		}
		return r;
	}




};

