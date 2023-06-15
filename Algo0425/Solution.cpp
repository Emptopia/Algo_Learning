#include "Solution.h"

vector<int> Solution::getLeastNumbers(vector<int>& arr, int k)
{
    //sort()����ֻ����ͨ�Ŀ������򣬳��˶���ͨ�Ŀ�����������Ż�����������˲�������Ͷ�����
        //���ݲ�ͬ�����������Լ���ͬ��������Զ�ѡ�ú��ʵ����򷽷���
        //���������ϴ�ʱ���ÿ������򣬷ֶεݹ顣
        //һ���ֶκ��������С��ĳ����ֵ��Ϊ����ݹ���ô�������Ķ��⸺�ɣ������ò�������
        //������ݹ��ι���г������������򣬻�����ö�����

    //sort����    ʱ��nlogn(����X����)     �ռ�logn(����)
    //vector<int>res;
    //sort(arr.begin(), arr.end());
    //int i = 0;
    //while (k > 0)
    //{
    //    res.push_back(arr[i]);
    //    k--;
    //    i++;
    //}
    //return res;

    //����� priority_queue  ʱ��nlogk(����Xk��������)     �ռ�k(ά�����k����)
    //vector<int>v(k, 0);
    //if (k == 0)return v;
    //priority_queue<int>q;
    //for (int i = 0; i < k; i++)
    //{
    //    q.push(arr[i]);
    //}
    //for (int i = k; i < arr.size(); i++)
    //{
    //    if (q.top() > arr[i])
    //    {
    //        q.pop();
    //        q.push(arr[i]);
    //    }
    //}
    //for (int i = 0; i < k; i++)
    //{
    //    v[i] = q.top();
    //    q.pop();
    //}
    //return v;
    
    //���� ��ͬ��sort    ʱ��nlogn
    //quickSort1(arr, 0, arr.size() - 1);
    //vector<int>res;
    //res.assign(arr.begin(), arr.begin() + k);
    //return res;

    //���ڿ�����������黮��    ʱ��n(���µݹ�ÿ��n/2���ȱ��������Ϊ2N-1,��ΪO(N))    �ռ�logn(ƽ���ݹ����)
    if (k >= arr.size())return arr;
    vector<int>res;
    quickSort2(arr, k, 0, arr.size() - 1);
    res.assign(arr.begin(), arr.begin() + k);
    return res;
}

void Solution::quickSort1(vector<int>& arr, int l, int r)
{
    //�����鳤��Ϊ1ʱ��ֹ�ݹ�
    if (l >= r)return;
    int i = l, j = r;
    while (i < j)
    {
        //��arr[l]Ϊ�ڱ�
        while (i<j && arr[j]>=arr[l])j--;
        while (i < j && arr[i] <= arr[l])i++;
        swap(arr[i], arr[j]);
    }
    //��ʱi=j
    swap(arr[i], arr[l]);
    //�ݹ������������ڱ����֣��ڱ�i����
    quickSort1(arr, l, i - 1);
    quickSort1(arr, i + 1, r);
}

void Solution::quickSort2(vector<int>& arr, int k, int l, int r)
{
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && arr[j] >= arr[l])j--;
        while (i < j && arr[i] <= arr[l])i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    if (i > k) quickSort2(arr, k, l, i - 1);
    if (i < k) quickSort2(arr, k, i + 1, r);
}
