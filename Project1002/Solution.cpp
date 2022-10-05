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
		//�ⷨ1��˫ָ�룬����ͼ�ɼ�
		//https://leetcode.cn/leetbook/read/illustration-of-algorithm/9p7s17/
												//��ʼ״̬				1 cur->2->3->null pre
		temp = cur->next;			//�ݴ��̽��			1 cur->2 temp->3->null pre
		cur->next = pre;				//�޸�����ָ��			null pre<- 1 cur     2 temp->3->null pre
		pre = cur;							//�ݴ���ʽ��			null<-1 pre cur      2 temp->3->null
		cur = temp;						//������һ�ڵ�			null<- 1pre			   2 cur temp->3->null
	}

	
	return pre;
	//�ⷨ2���ݹ飬����ֻʵ������ķ�ת
	//class Solution {
	//	public:
	//		void reverseList(ListNode head) {
	//		recur(head, null);    // ���õݹ�
	//	}
	//	//ע������recur�����ķ���ֵ��ʱΪvoid
	//	private:
	//		void recur(ListNode cur, ListNode pre) {

	//		//��ֹ������
	//		if (cur == null) return;

	//		//���ƣ�Ŀ���ǵ��Ƶ�����null
	//		recur(cur.next, cur);

	//		//���ݣ���cur.nextΪnull��ʱ���β�cur����null��������ֹ���������Կ�ʼ����
	//		//���ｫcur.next��Ϊָ��ǰһ�����pre
	//		cur.next = pre;
	//	}
	//}

	//���ߣ�����ľ
	//	���ӣ�https://leetcode.cn/leetbook/read/illustration-of-algorithm/9p7s17/?discussion=qdocfK
	//��Դ�����ۣ�LeetCode��
	//	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}

Node* Solution::copyRandomList(Node* head)
{
	if (head == nullptr) return nullptr;
	Node* cur = head;										//��ʱָ��
	unordered_map<Node*, Node*> map;
	// 3. ���Ƹ��ڵ㣬������ ��ԭ�ڵ� -> �½ڵ㡱 �� Map ӳ��
	while (cur != nullptr) {
		map[cur] = new Node(cur->val);			//(map[ԭ�ڵ�(��Ϊ��)])  �½ڵ� =  new Node(ԭ�ڵ��val);			�������е�val���½ڵ��У���Ӧ���õ���ԭ����ָ��
		cur = cur->next;
	}
	cur = head;													//ָ������
	// 4. ����������� next �� random ָ��
	while (cur != nullptr) {
		map[cur]->next = map[cur->next];				//�½ڵ�->next = [��Ӧԭ�ڵ�->next]��Ϊ��       �����ص��½ڵ�
		map[cur]->random = map[cur->random];		//ͬ��
		cur = cur->next;
	}
	// 5. �����������ͷ�ڵ�
	return map[head];												//����ԭ�ڵ���Ϊ��  ��ֵ

		//���ӣ�https://leetcode.cn/leetbook/read/illustration-of-algorithm/9plk45/


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
	//���ַ�������ϰ
	int left = 0;
	int right = nums.size();			//��Ϊsizeȡ��������������������ҿ���ȫ����  right = m;
	//�˴����������ұգ�Ҫ��left<right-1
	while (left < right)					//��߽�
	{
		int m = (left + right) / 2;
		if (nums[m] == target)		//��ȣ�����С�����䣬������ƫ��
			right = m;
		else if (nums[m] < target)	//ƫС������С������
			left = m + 1;
		else if (nums[m] > target)	//ƫ������С������
			right = m;
	}
	int Left = left;
	cout << Left << endl;
	left = 0;
	right = nums.size();
	while (left < right)
	{
		int m = (left + right) / 2;
		if (nums[m] == target)		//��ȣ�����С�����䣬������ƫ�ҡ�
			left = m + 1;
		else if (nums[m] < target)	//ƫС������С�����䣨ͬ��
			left = m + 1;
		else if (nums[m] > target)	//ƫ������С�����䣨ͬ��
			right = m;
	}
	int Right = left;					//�ұ߽�
	cout << Right << endl;

	return Right - Left ;
}

int Solution::missingNumber(vector<int>& nums)
{
	//1����������
	
	//2������
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int m = (left + right) / 2;
		if (nums[m] == m)			//��ȼ�����ƫ�󣬹���С������
			left = m + 1;
		else
			right = m;					//����������ƫ�ң����߾���ȱʧλ������С������
	}
										//���һ��left+1ʱ����=�ң�left����right�����ķǵ�λ�ã���������
	return left;					//���ַ��ػ�������left

	//3����ѧ
	//int length = nums.size();
	//int sum = (0 + length) * (length + 1) / 2;			//(a0+an)*n/2			�Ȳ�������͹�ʽ
	////0 �� length ֮���ܹ���length + 1λ��
	//for (int i = 0; i < length; i++)
	//	sum -= nums[i];
	//return sum;

	//4��λ����				�����н����ɣ�ֻ��Ҫ�����е����ֶ����һ�飬���յĽ����������Ҫ����Ǹ����֡�
	//if (nums.length <= 0) {
	//	return 0;
	//}
	//int xor = 0;
	//for (int i = 0; i < nums.size(); i++)
	//	xor = xor ^nums[i] ^ (i + 1);
	////0 �� length ֮���ܹ���length + 1λ��
	////����nums[]���±�Ϊ0��length - 1
	////i��ʵ���±�Ӧ��Ϊ 1��length +1
	//return xor;

	//5����ϣ��
	//Set<Integer> numSet = new HashSet<Integer>();				c++��unordered_map
	//for (int num : nums) numSet.add(num);								��������nums��Ա

	//int expectedNumCount = nums.length + 1;
	//for (int number = 0; number < expectedNumCount; number++) {
	//	if (!numSet.contains(number)) {											����0~size����������򷵻�
	//		return number;
	//	}
	//}
	//return -1;



	//���ߣ�Yawn
	//	���ӣ�https://leetcode.cn/leetbook/read/illustration-of-algorithm/58iqo5/?discussion=8xox7M
	//��Դ�����ۣ�LeetCode��
	//	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

}