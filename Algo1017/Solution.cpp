#include "Solution.h"

void Solution::Lprint(ListNode* head)
{
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* dum = new ListNode(0);
	ListNode* cur = dum;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val <= l2->val)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = l1 != nullptr ? l1 : l2;

	return dum->next;


	//�Լ��Ľⷨ����������
	//ListNode* res = l1;
	//if (l1 == nullptr && l2 == nullptr)
	//	return nullptr;
	//else if (l1 == nullptr)
	//	return l2;
	//else if (l2 == nullptr)
	//	return l1;
	//ListNode* p1;
	//ListNode* p2;
	//if (l1->val <= l2->val)
	//{
	//	p1 = l1;				//p1Ϊ��ʼ��С��
	//	p2 = l2;
	//}
	//else
	//{
	//	p1 = l2;				
	//	p2 = l1;
	//	res = l2;
	//}
	//while (p1 != nullptr && p2!= nullptr)
	//{
	//	if (p2->val >= p1->val && (p1->next == nullptr) || (p2->val < p1->next->val))
	//	{
	//		ListNode* temp = p2;
	//		p2 = p2->next;
	//		temp->next = p1->next;
	//		p1->next = temp;
	//		p1 = p1->next;
	//	}
	//	else
	//		p1 = p1->next;
	//}
	//return res;
}

ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	ListNode* A = headA, * B = headB;
	while (A != B)
	{
		A = A == nullptr ? headB : A->next;			//AB����������󣬽���������ڶ��ξ����ڵ�ʱ��AB����
		B = B == nullptr ? headA : B->next;

	}
	return A;

	//�Լ�д�ı�������N�����Ӷȣ�����������
	//ListNode* temp;
	//while (headA != nullptr)
	//{
	//	temp = headB;
	//	while (temp != nullptr)
	//	{
	//		if (headA == temp)
	//			return temp;
	//		temp = temp->next;
	//	}
	//	headA = headA->next;
	//}
	//return nullptr;

	
}

vector<int> Solution::exchange(vector<int>& nums)
{
	if (nums.empty())
		return {};
	int n2 = 0, n1;
	for (n2; n2 < nums.size(); n2++)
	{
		if (nums[n2] % 2 == 0)
			break;
	}
	for (n1 = n2 + 1; n1 < nums.size(); n1++)
	{
		if (nums[n1] % 2 == 1)			//������������
		{
			int temp = nums[n1];
			nums[n1] = nums[n2];
			nums[n2] = temp;
			n2++;
		}
	}
	return nums;


	//��⣺˫��ָ�룬����
	//int i = 0, j = nums.size() - 1;
	//while (i < j)
	//{
	//	while (i < j && (nums[i] & 1) == 1) i++;
	//	while (i < j && (nums[j] & 1) == 0) j--;
	//	swap(nums[i], nums[j]);
	//}
	//return nums;

}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		if (nums[left] + nums[right] > target)
			right--;
		else if (nums[left] + nums[right] < target)
			left++;
		else
			return { nums[left],nums[right] };

	}
	return {};



}

string Solution::reverseWords(string s)
{
	if (s.empty())
		return {};
	string res;
	int right = s.size() - 1, left = 0;
	while (s[right] == ' ')
	{
		right--;
		if (right < 0)
			return {};
	}
	while (s[left] == ' ')
	{
		left++;
	}
	s = s.substr(left, right - left +1);
	right = s.size() - 1, left = right;
	while (left != 0)
	{
		if (s[left] == ' ')
		{
			res.append(s, left+1, right - left);
			while (left != 0 && s[left - 1] == ' ')
			{
				left--;
			}
			right = left - 1;
			res.append(" ");
		}
		left--;
	}
	res.append(s, 0, right +1);
	return res;

}

bool Solution::dp1(vector<vector<char>>& board, string& word,int i, int j, int k)		//ע������wordΪ���ý�ʡ����ʱ��
{
	if (k  == word.size())
	{
		cout << "�������յ�" << endl;
		return true;
	}
	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k])
		return false;
	board[i][j] = ' ';
	cout << "����" << i << " " << j << " k=" << k << endl;
	bool res =  dp1(board,word,i+1, j, k+1) || dp1(board, word, i - 1, j, k + 1) || dp1(board, word, i, j + 1, k + 1) || dp1(board, word, i, j -1, k + 1);
	board[i][j] = word[k];
	return res;
}

bool Solution::exist(vector<vector<char>>& board, string word)
{
	//�Լ�д��

	//int m = board.size();
	//int n = board[0].size();
	//unordered_map<int,int>path;
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		bool res = true;
	//		if (board[i][j] == word[0])
	//		{
	//			cout << "�������У� " << i << " " << j << endl;
	//			int ti = i, tj = j;
	//			path[ti * 10 + tj]++;
	//			cout << ti * 10 + tj << " = " << path[ti * 10 + tj] << endl;
	//			for (int k = 1; k < word.size(); k++)
	//			{
	//				if (ti != m - 1 && board[ti + 1][tj] == word[k] && path[(ti + 1) * 10 + tj] != 1) 
	//				{
	//					path[(ti + 1) * 10 + tj]++;
	//					cout << (ti + 1) * 10 + tj << " = " << path[(ti + 1) * 10 + tj] << endl;
	//					ti++;
	//				}
	//				else if (ti != 0 && board[ti - 1][tj] == word[k] && path[(ti - 1) * 10 + tj] != 1)
	//				{
	//					path[(ti - 1) * 10 + tj]++;
	//					cout << (ti - 1) * 10 + tj << " = " << path[(ti - 1) * 10 + tj] << endl;
	//					ti--;
	//				}
	//				else if (tj != n - 1 && board[ti][tj + 1] == word[k] && path[ti * 10 + tj + 1] != 1)
	//				{
	//					path[ti * 10 + tj + 1]++;
	//					cout << ti * 10 + tj + 1 << " = " << path[ti * 10 + tj + 1] << endl;
	//					tj++;
	//				}
	//				else if (tj != 0 && board[ti][tj - 1] == word[k] && path[ti * 10 + tj - 1] != 1)
	//				{
	//					path[ti * 10 + tj - 1]++;
	//					cout << ti * 10 + tj - 1 << " = " << path[ti * 10 + tj - 1] << endl;
	//					tj--;
	//				}
	//				else
	//				{
	//					cout << "�Ҳ������ظ�" << endl;
	//					res = false;
	//					break;
	//				}
	//			}
	//		}
	//		else
	//		{
	//			continue;
	//		}
	//		if (res == true)
	//			return res;
	//		path = {};		//forѭ������жϣ������²��ң���ϣ����
	//	}
	//}
	//return false;

	//�ݹ�
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == word[0])
			{
				cout << "������㣺" << i << " " << j << endl;
				if (dp1(board, word, i, j, 0) == true)
					return true;
			}

		}
	}
	return false;
}

int Solution::dp2(int i, int j, int m, int n, int k, vector<vector<int>>&mark)
{
	if (i < 0 || i >= m || j<0 || j >= n || mark[i][j] != 0 || i % 10 + i / 10 + j % 10 + j / 10 > k)
		return 0;			//���߸��ӵ������Խ�硢�Ѿ��߹�����k��
	mark[i][j] = 1;
	cout << "�Ѿ���" << i << "��" << j << "��" << endl;		
	int res = 1 + dp2(i + 1, j, m, n, k, mark) + dp2(i - 1, j, m, n, k, mark) 
		+ dp2(i , j+1, m, n, k, mark) + dp2(i , j -1, m, n, k, mark);		//�ĸ���������
	return res;
}

int Solution::movingCount(int m, int n, int k)
{
	vector<int>temp(n, 0);
	vector<vector<int>>mark;
	for (int i = 0; i < m; i++)				//��ʼ��m��n�е����飬�������ڱ��Ϊ�߹��ĸ���
	{
		mark.push_back(temp);
	}
	return dp2(0, 0, m, n, k, mark);
}

void Solution::dp3(TreeNode* root, int target, vector<vector<int>>&res, vector<int>&temp, int sum)
{
	if (root == nullptr)
		return;
	sum += root->val;
	if (sum == target && root->left == nullptr && root->right == nullptr)		//���ܺ�Ϊsum���ڵ�ΪҶ
	{
		temp.push_back(root->val);
		res.push_back(temp);
		temp.pop_back();
		return;
	}
	temp.push_back(root->val);

	dp3(root->left, target, res, temp, sum);				
	dp3(root->right, target, res, temp, sum);		//right�ӵݹ�
	temp.pop_back();			//����pop�󣬲������������ϸ��ݹ��right�ӵݹ�
}
vector<vector<int>> Solution::pathSum(TreeNode* root, int target)
{
	vector<vector<int>>res;
	vector<int>temp;
	int sum = 0;
	dp3(root, target, res, temp, sum);
	return res;
}

void Solution::recur4(Node* cur)
{
	if (cur == nullptr)
		return;
	recur4(cur->left);				//������������ṹ��left,����,right		
	if (pre == nullptr)			//��һ�α���ʱ������pre��head
	{
		head = cur;
		pre = cur;
	}
	else
	{	
		cur->left = pre;			//���ǵ�һ�α�������pre��cur���ӣ�pre����Ϊcur
		pre->right = cur;
		pre = cur;
	}
	recur4(cur->right);			//cur�����ű������죬����Ҫ����

}

Node* Solution::treeToDoublyList(Node* root)
{
	if (root == nullptr)
		return root;
	pre = nullptr;				//��ʼ��pre
	recur4(root);			//ת������
	head->left = pre;			//ͷβѭ��
	pre->right = head;
	return head;
}

void Solution::recur5(TreeNode* root)
{
	if (root == nullptr)return;
	recur5(root->left);
	nums.push_back(root->val);
	recur5(root->right);
}

int Solution::kthLargest(TreeNode* root, int k)
{
	recur5(root);
	return nums[nums.size() - k];
}

bool cmp1(string& s1,  string& s2)
{
	//���ļ���д������⣬�ܹ֣����������������
	//���ز���ʽ��ѡ��     д���¹�����   ��Ա1(s1)��Сʱ������1�Ĳ���ʽ(s1<s2)
	return s1 + s2 < s2 + s1;
}


string Solution::minNumber(vector<int>& nums)
{
	vector<string>strs;
	string res;
	for (int i = 0; i < nums.size(); i++)
	{
		strs.push_back(to_string(nums[i]));
	}
	sort(strs.begin(), strs.end(),cmp1);		//ps��greater<int>()�Դ��Ľ���������
	for (int i = 0; i < strs.size(); i++)
	{
		res.append(strs[i]);
	}
	return res;

}

bool Solution::isStraight(vector<int>& nums)
{
	set<int>s;
	int mi = 14;
	int ma = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)continue;
		mi = min(mi, nums[i]);
		ma = max(ma, nums[i]);
		if (s.find(nums[i]) != s.end())return false;
		s.insert(nums[i]);
	}
	if (ma - mi < 5)return true;
	else return false;
}