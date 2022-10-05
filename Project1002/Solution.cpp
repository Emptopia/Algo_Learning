#include "Solution.h"

vector<int> Solution::reversePrint(ListNode* head)
{
	vector<int>res;
	ListNode* ptr = head;
	while (ptr != nullptr)
	{
		res.push_back(ptr->val);
		ptr = ptr->next;
	}
	reverse(res.begin(),res.end());
	return res;
}

ListNode* Solution::reverseList(ListNode* head)
{
	ListNode* pre = nullptr;
	ListNode* cur = head;
	ListNode* temp;
	while (cur != nullptr)
	{
		//解法1，双指针，清晰图可见
		//https://leetcode.cn/leetbook/read/illustration-of-algorithm/9p7s17/
												//初始状态				1 cur->2->3->null pre
		temp = cur->next;			//暂存后继结点			1 cur->2 temp->3->null pre
		cur->next = pre;				//修改引用指向			null pre<- 1 cur     2 temp->3->null pre
		pre = cur;							//暂存访问结点			null<-1 pre cur      2 temp->3->null
		cur = temp;						//访问下一节点			null<- 1pre			   2 cur temp->3->null
	}

	
	return pre;
	//解法2，递归，首先只实现链表的反转
	//class Solution {
	//	public:
	//		void reverseList(ListNode head) {
	//		recur(head, null);    // 调用递归
	//	}
	//	//注意这里recur方法的返回值暂时为void
	//	private:
	//		void recur(ListNode cur, ListNode pre) {

	//		//终止条件：
	//		if (cur == null) return;

	//		//递推：目的是递推到最后的null
	//		recur(cur.next, cur);

	//		//回溯：当cur.next为null的时候，形参cur就是null，满足终止条件，所以开始回溯
	//		//这里将cur.next改为指向前一个结点pre
	//		cur.next = pre;
	//	}
	//}

	//作者：张子木
	//	链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/9p7s17/?discussion=qdocfK
	//来源：力扣（LeetCode）
	//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}

Node* Solution::copyRandomList(Node* head)
{
	if (head == nullptr) return nullptr;
	Node* cur = head;										//临时指针
	unordered_map<Node*, Node*> map;
	// 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
	while (cur != nullptr) {
		map[cur] = new Node(cur->val);			//(map[原节点(即为键)])  新节点 =  new Node(原节点的val);			复制所有的val到新节点中，对应键用的是原链表指针
		cur = cur->next;
	}
	cur = head;													//指针重置
	// 4. 构建新链表的 next 和 random 指向
	while (cur != nullptr) {
		map[cur]->next = map[cur->next];				//新节点->next = [对应原节点->next]作为键       所返回的新节点
		map[cur]->random = map[cur->random];		//同理
		cur = cur->next;
	}
	// 5. 返回新链表的头节点
	return map[head];												//返回原节点作为键  的值

		//链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/9plk45/


}

string Solution::replaceSpace(string s)
{
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			res.push_back(s[i]);
		else
			res.append("%20");
	}
	return res;

}

string Solution::reverseLeftWords(string s, int n)
{
	//string res;
	//res.append(s, n, s.size()-1);
	//res.append(s, 0, n);
	return s.substr(n, s.size() - 1) + s.substr(0, n);
}

int Solution::findRepeatNumber(vector<int>& nums)
{
	//set<int>s;
	//for (int i = 0; i < nums.size(); i++)
	//{
	//	s.insert(nums[i]);
	//	if (s.size() == i)
	//		return nums[i];
	//}
	//return -1;

	unordered_map<int, bool> map;
	for (int i = 0; i < nums.size(); i++)
	{
		if (map[nums[i]] == true)
			return nums[i];
		map[nums[i]] = true;
	}
	return -1;


}

int Solution::search(vector<int>& nums, int target)
{
	//二分法，待复习
	int left = 0;
	int right = nums.size();			//因为size取不到，所以区间是左闭右开，全程让  right = m;
	//此处如果用左闭右闭，要用left<right-1
	while (left < right)					//左边界
	{
		int m = (left + right) / 2;
		if (nums[m] == target)		//相等，则缩小右区间，让整体偏左。
			right = m;
		else if (nums[m] < target)	//偏小，则缩小左区间
			left = m + 1;
		else if (nums[m] > target)	//偏大，则缩小右区间
			right = m;
	}
	int Left = left;
	cout << Left << endl;
	left = 0;
	right = nums.size();
	while (left < right)
	{
		int m = (left + right) / 2;
		if (nums[m] == target)		//相等，则缩小左区间，让整体偏右。
			left = m + 1;
		else if (nums[m] < target)	//偏小，则缩小左区间（同上
			left = m + 1;
		else if (nums[m] > target)	//偏大，则缩小右区间（同上
			right = m;
	}
	int Right = left;					//右边界
	cout << Right << endl;

	return Right - Left ;
}

int Solution::missingNumber(vector<int>& nums)
{
	//1、暴力，略
	
	//2、二分
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int m = (left + right) / 2;
		if (nums[m] == m)			//相等即代表偏左，故缩小左区间
			left = m + 1;
		else
			right = m;					//不相等则代表偏右，或者就在缺失位，故缩小右区间
	}
										//最后一次left+1时，左=右，left到达right所处的非等位置，即所需结果
	return left;					//二分返回基本都是left

	//3、数学
	//int length = nums.size();
	//int sum = (0 + length) * (length + 1) / 2;			//(a0+an)*n/2			等差数列求和公式
	////0 到 length 之间总共有length + 1位数
	//for (int i = 0; i < length; i++)
	//	sum -= nums[i];
	//return sum;

	//4、位运算				异或具有交换律，只需要把所有的数字都异或一遍，最终的结果就是我们要求的那个数字。
	//if (nums.length <= 0) {
	//	return 0;
	//}
	//int xor = 0;
	//for (int i = 0; i < nums.size(); i++)
	//	xor = xor ^nums[i] ^ (i + 1);
	////0 到 length 之间总共有length + 1位数
	////但是nums[]的下标为0，length - 1
	////i的实际下标应该为 1，length +1
	//return xor;

	//5、哈希表
	//Set<Integer> numSet = new HashSet<Integer>();				c++用unordered_map
	//for (int num : nums) numSet.add(num);								加入所有nums成员

	//int expectedNumCount = nums.length + 1;
	//for (int number = 0; number < expectedNumCount; number++) {
	//	if (!numSet.contains(number)) {											遍历0~size，如果不含则返回
	//		return number;
	//	}
	//}
	//return -1;



	//作者：Yawn
	//	链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/58iqo5/?discussion=8xox7M
	//来源：力扣（LeetCode）
	//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

}