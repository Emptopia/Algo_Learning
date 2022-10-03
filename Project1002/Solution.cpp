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