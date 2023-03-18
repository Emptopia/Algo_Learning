#include "Solution.h"
#include<stack>
#include<string>
#include<unordered_map>
int Solution::removeDuplicates(vector<int>& nums)
{
	int left = 0, right = 1;
	for (int right = 1; right < nums.size(); right++)
	{
		if (nums[right] != nums[left])
		{
			left++;
			nums[left] = nums[right]; 
		}
		
	}

	return left+1;
}
bool Solution::isValid(string s)
{
	stack<int>st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')st.push(s[i]);
		else
		{
			if (st.empty())return false;
			if (s[i] == ')' && st.top() == '(')st.pop();
			else if (s[i] == '}' && st.top() == '{')st.pop();
			else if (s[i] == ']' && st.top() == '[')st.pop();
			else return false;
		}
	}
	if(st.empty())return true;
	return false;
}

bool Solution::isPalindrome(int x)
{
	string s = to_string(x);
	stack<char>st;
	string temp;
	for (int i = 0; i < s.size(); i++)
	{
		st.push(s[i]);
	}
	while(!st.empty())
	{
		temp.push_back(st.top());
		st.pop();
	}
	if (s == temp)return true;

	return false;
}

int Solution::removeElement(vector<int>& nums, int val)
{
	int left = 0;
	for (int right = 0; right < nums.size(); right++)
	{
		if (nums[right] != val)
		{
			nums[left] = nums[right];
			left++;
		}

	}
	return left;
}

int Solution::searchInsert(vector<int>& nums, int target)
{
	//二分  可以多收集题型。专项突破
	int l = 0, r = nums.size() - 1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		//这里可直接用<=
		if (target < nums[m])			r = m - 1;
		else if (target > nums[m])	l = m + 1;
		else										return m;		
	}
	return l;
}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
	ListNode* preHead = new ListNode(-1);
	ListNode* prev = preHead;
	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->val < list2->val)
		{
			prev->next = list1;
			list1 = list1->next;
		}
		else
		{
			prev->next = list2;
			list2 = list2->next;
		}
		prev = prev->next;
	}
	prev->next = list1 == nullptr ? list2 : list1;
	return preHead->next;
}

string Solution::longestCommonPrefix(vector<string>& strs)
{
	string res;
	if (strs[0].empty())return "";
	
	for (int i = 0; i < strs[0].size(); i++)
	{
		char temp = strs[0][i];
		bool r = true;
		for (int j = 0; j < strs.size(); j++)
		{
			if (strs[j].size() < i+1 || strs[j][i] != temp)
			{
				r = false;
				break;
			}
		}
		if (r == false)break;
		else res += temp;
	}

	return res;
}

int Solution::romanToInt(string s)
{
	unordered_map<char, int>m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	int res = 0;

	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] == 'I')
		{
			if (s[i + 1] == 'V' || s[i + 1] == 'X')res -= m['I'];
			else res += m['I'];
		}
		else if (s[i] == 'X')
		{
			if (s[i + 1] == 'L' || s[i + 1] == 'C')res -= m['X'];
			else res += m['X'];
		}
		else if (s[i] == 'C')
		{
			if (s[i + 1] == 'D' || s[i + 1] == 'M')res -= m['C'];
			else res += m['C'];
		}
		else res += m[s[i]];
		//cout << "res=" << res << " ";
	}
	res += m[s[s.size() - 1]];


	return res;
}

void Solution::moveZeroes(vector<int>& nums)
{
	int l = 0, r = 0;
	while (r < nums.size())
	{
		if (nums[r] == 0)r++;
		else if (nums[l] == 0)
		{
			nums[l] = nums[r];
			nums[r] = 0;
			r++;
			l++;
		}
		else
		{
			r++;
			l++;
		}
	}

}

int Solution::climbStairs(int n)
{
	int dp[46];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int Solution::maxProfit(vector<int>& prices)
{
	int pro[100001];
	pro[0] = 0;
	int mi = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		pro[i] = max(pro[i - 1], prices[i] - mi);
		mi = min(mi, prices[i]);
		//cout << "pro" << i << "=" << pro[i] << endl;
	}

	return pro[prices.size()-1];
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int p1 = m - 1, p2 = n - 1;
	int tail = m + n - 1;
	int cur;
	while (p1 >= 0 || p2 >= 0)
	{
		if (p1 == -1)cur = nums2[p2--];
		else if (p2 == -1) cur = nums1[p1--];
		else if (nums1[p1] > nums2[p2])cur = nums1[p1--];
		else cur = nums2[p2--];
		
		nums1[tail--] = cur;
	}

}

vector<int> Solution::plusOne(vector<int>& digits)
{
	vector<int>res;
	int len = digits.size() - 1;
	digits[len]++;
	for (int i = len; i >= 0; i--)
	{
		if (digits[i] == 10)
		{
			digits[i] = 0;
			if (i != 0)digits[i - 1]++;
			else res.push_back(1);
		}
		else break;
	}
	if (res.empty())return digits;
	for (int i = 0; i <=len; i++)res.push_back(digits[i]);


	return res;
}

int Solution::maxDepth(TreeNode* root)
{
	if (root == nullptr)return 0;
	int res = max(maxDepth(root->left), maxDepth(root->right)) + 1;
	return res;
}

bool Solution::hasCycle(ListNode* head)
{
	unordered_set<ListNode*>s;
	while (head != nullptr)
	{
		if (s.count(head)) return true;
		s.insert(head);
		head = head->next;
	}
	return false;
}

int Solution::search(vector<int>& nums, int target)
{
	int l = 0, r = nums.size() - 1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (nums[m] == target)return m;
		else if (nums[m] < target)l = m + 1;
		else r = m - 1;
	}
	return -1;
}

int Solution::lengthOfLastWord(string s)
{
	int tail = s.size() - 1;
	while (s[tail] == ' ')
	{
		tail--;
	}
	int head = tail;
	while (head >=0 && s[head] != ' ')
	{
		head--;
	}
	return tail - head;
}

int Solution::findRepeatNumber(vector<int>& nums)
{
	unordered_set<int>s;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = s.find(nums[i]);
		if (s.count(nums[i]))return nums[i];
		s.insert(nums[i]);
	}

	return -1;
}



bool Solution::isSymmetric(TreeNode* root)
{
	return check1(root, root);
}

bool Solution::check1(TreeNode* t1, TreeNode* t2)
{
	if (!t1 && !t2)return true;
	if (!t1 || !t2)return false;
	
	return t1->val == t2->val && check1(t1->left, t2->right) && check1(t1->right, t2->left);
}
