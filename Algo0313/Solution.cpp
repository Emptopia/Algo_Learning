#include "Solution.h"

vector<int> Solution::inorderTraversal(TreeNode* root)
{
	//遍历
	//vector<int>res;
	//inorder(root, res);
	//return res;

	//迭代
	vector<int>res;
	stack<TreeNode*>stk;
	while (root != nullptr || !stk.empty())
	{
		while (root != nullptr)
		{
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		res.push_back(root->val);
		root = root->right;

	}
	return res;
}

TreeNode* Solution::invertTree(TreeNode* root)
{
	if (!root)return nullptr;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

int Solution::singleNumber(vector<int>& nums)
{
	//异或性质
		//1、0^a = a
		//2、a^a =0;
		//3、^满足交换律结合律，因此最后留下的数就是只出现一次的数字
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		res = res ^ nums[i];
	}
	return res;
}

int Solution::minDepth(TreeNode* root)
{
	if (!root)return 0;
	if (root->left == nullptr && root->right == nullptr)return 1;
	int ma = INT_MAX;
	if (root->left != nullptr)
	{
		ma = min(minDepth(root->left), ma);
	}
	if (root->right != nullptr)
	{
		ma = min(minDepth(root->right), ma);
	}
	return ma + 1;

}

ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	//哈希
	//unordered_set<ListNode*>s;
	//while (headA)
	//{
	//	s.insert(headA);
	//	headA = headA->next;
	//}
	//while (headB)
	//{
	//	if (s.count(headB))return headB;
	//	s.insert(headB);
	//	headB = headB->next;
	//}
	//return nullptr;

	//双指针
	if (!headA || !headB)return NULL;
	ListNode* p1 = headA;
	ListNode* p2 = headB;
	//第二遍遍历时，有相交总会相交，否则最后将同时等于nullptr
	while (p1 != p2)
	{
		p1 = p1 == nullptr ? headB : p1->next;
		p2 = p2 == nullptr ? headA : p2->next;
	}
	return p1;
}

int Solution::majorityElement(vector<int>& nums)
{
	int len = nums.size();
	unordered_map<int, int>m;
	for (int i = 0; i < len; i++) 
		m[nums[i]]++;

	for (int i = 0; i < len; i++)
	{
		if (m[nums[i]] > (len / 2)) return nums[i];
	}


	return 0;
}

int Solution::mySqrt(int x)
{
	int l = 0, r = x;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if ((long long)m * m < x)l = m + 1;
		else if ((long long)m * m > x) r = m - 1;
		else return m;
	}
	return r;
}

void Solution::reverseString(vector<char>& s)
{
	int l = 0, r = s.size() - 1;
	while (l < r)
	{
		char temp = s[l];
		s[l] = s[r];
		s[r] = temp;
		l++;
		r--;
	}
}

ListNode* Solution::getKthFromEnd(ListNode* head, int k)
{

	return nullptr;
}

string Solution::replaceSpace(string s)
{
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')res += "%20";
		else res += s[i];
	}


	return res;
}

void Solution::inorder(TreeNode* root, vector<int>& nums)
{
	if (!root)return;
	inorder(root->left, nums);
	nums.push_back(root->val);
	inorder(root->right, nums);
	
}
