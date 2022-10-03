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