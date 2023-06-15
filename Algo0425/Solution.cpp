#include "Solution.h"

vector<int> Solution::getLeastNumbers(vector<int>& arr, int k)
{
    //sort()并非只是普通的快速排序，除了对普通的快速排序进行优化，它还结合了插入排序和堆排序。
        //根据不同的数量级别以及不同情况，能自动选用合适的排序方法。
        //当数据量较大时采用快速排序，分段递归。
        //一旦分段后的数据量小于某个阀值，为避免递归调用带来过大的额外负荷，便会改用插入排序。
        //而如果递归层次过深，有出现最坏情况的倾向，还会改用堆排序。

    //sort排序    时间nlogn(数组X排序)     空间logn(排序)
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

    //大根堆 priority_queue  时间nlogk(数组Xk个数排序)     空间k(维护最多k个数)
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
    
    //快排 等同于sort    时间nlogn
    //quickSort1(arr, 0, arr.size() - 1);
    //vector<int>res;
    //res.assign(arr.begin(), arr.begin() + k);
    //return res;

    //基于快速排序的数组划分    时间n(向下递归每次n/2，等比数列求和为2N-1,故为O(N))    空间logn(平均递归深度)
    if (k >= arr.size())return arr;
    vector<int>res;
    quickSort2(arr, k, 0, arr.size() - 1);
    res.assign(arr.begin(), arr.begin() + k);
    return res;
}

void Solution::quickSort1(vector<int>& arr, int l, int r)
{
    //子数组长度为1时终止递归
    if (l >= r)return;
    int i = l, j = r;
    while (i < j)
    {
        //以arr[l]为哨兵
        while (i<j && arr[j]>=arr[l])j--;
        while (i < j && arr[i] <= arr[l])i++;
        swap(arr[i], arr[j]);
    }
    //此时i=j
    swap(arr[i], arr[l]);
    //递归左右子数组哨兵划分，哨兵i不动
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
