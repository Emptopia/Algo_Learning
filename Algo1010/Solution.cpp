#include "Solution.h"

bool Solution::findNumberIn2DArray(vector<vector<int>>&matrix, int target)
{
	if (matrix.empty())
		return false;
	int row = matrix.size();
	int column = matrix[0].size();
	//1、暴力
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < column; j++)
	//	{
	//		if (matrix[i][j] == target)
	//			return true;
	//	}
	//}
	//return false;

	//2、按规则遍历					//力扣跑起来更耗时，笑死
	int i = row - 1;
	int j = 0;
	while (i >= 0 && j < column)
	{
		if (matrix[i][j] > target)
			i--;
		else if (matrix[i][j] < target)
			j++;
		else
			return true;
	}
	return false;
}

int Solution::minArray(vector<int>& numbers)
{
	//暴力
	//for (int i = 0; i < numbers.size()-1; i++)
	//{
	//	if (numbers[i] > numbers[i + 1])
	//		return numbers[i + 1];
	//}
	//return numbers[0];

	//二分
	int left = 0;
	int right = numbers.size() - 1;
	while (left < right)
	{
		int m = (left + right) / 2;
		if (numbers[m] > numbers[right])
			left = m + 1;
		else if (numbers[m] < numbers[right])
			right = m;
		else
			right--;
	}
	return numbers[left];
}

char Solution::firstUniqChar(string s)
{
	map<char, int>m;
	for (char i : s)
	{
		m[i]++;
	}
	for (char i : s)
	{
		if (m[i] == 1)
			return i;
	}
	return ' ';
}

//void Solution::helper1(TreeNode* root, vector<int>&res)
//{
//	res.push_back(root->val);
//	if (root->left != nullptr)
//		helper1(root->left,res);
//	if (root->right != nullptr)
//		helper1(root->right,res);
//}

vector<int> Solution::levelOrder(TreeNode* root)
{
	//			自己的递归，实现先左后右打印（怪）
	//if (root == nullptr)
	//	return {};
	//vector<int>res;
	//helper1(root, res);
	//return res;

	//BFS广度优先搜索   按层打印
	//队列
	if (root == nullptr)
		return {};
	vector<int>res;
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		res.push_back(temp->val);
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	return res;
}

vector<vector<int>> Solution::levelOrder2(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == nullptr)
		return {};
	queue<TreeNode*>q;
	q.push(root);
	vector<int>tmp;
	while (!q.empty())
	{
		for (int i = q.size(); i > 0; i--)
		{
			TreeNode* temp = q.front();
			q.pop();
			tmp.push_back(temp->val);
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		res.push_back(tmp);
		tmp = {};
	}
	return res;

}

vector<vector<int>> Solution::levelOrder3(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == nullptr)
		return {};
	queue<TreeNode*>q;
	q.push(root);
	vector<int>tmp;
	while (!q.empty())
	{
		for (int i = q.size(); i > 0; i--)
		{
			TreeNode* temp = q.front();
			q.pop();
			tmp.push_back(temp->val);
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		if (res.size() % 2 == 1)
			reverse(tmp.begin(),tmp.end());
		res.push_back(tmp);
		tmp = {};
	}
	return res;

}

bool Solution::recur(TreeNode* A, TreeNode* B)			
{
	//内层遍历		遍历该子树是否包含B
	//B为空则遍历结束，返回true
	//A为空或AB值不等，返回false
	//AB值相等，则继续遍历AB左右子树
	if (B == nullptr)		//B子树不存在时，不需要比较A
		return true;
	if (A == nullptr || A->val != B->val)
		return false;
	return recur(A->left, B->left) && recur(A->right, B->right);
}

bool Solution::isSubStructure(TreeNode* A, TreeNode* B)			
{
	//外层遍历
	//AB为空则false
	//内层遍历为true时，返回true
	//A左右子树和B树遍历为true时，返回true
	return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
}

void Solution::recur2(TreeNode* Node)
{
	if (Node == nullptr)
		return;
	TreeNode* temp;
	if (Node->left != nullptr && Node->right != nullptr)
	{
		temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}
	else if (Node->left != nullptr)
	{
		Node->right = Node->left;
		Node->left = nullptr;
	}
	else if (Node->right != nullptr)
	{
		Node->left = Node->right;
		Node->right = nullptr;
	}
	recur2(Node->left);
	recur2(Node->right);
}

TreeNode* Solution::mirrorTree(TreeNode* root)
{
	//官方解法
	//if (root == nullptr) return nullptr;				//如果遍历到空指针则直接返回
	//TreeNode* tmp = root->left;						//temp
	//root->left = mirrorTree(root->right);			//两边交换赋值遍历即可
	//root->right = mirrorTree(tmp);
	//return root;

	recur2(root);
	return root;

}

bool Solution::recur3(TreeNode* A, TreeNode* B)
{
	if (A == nullptr && B == nullptr)
		return true;
	if (A == nullptr || B == nullptr || A->val != B->val)
		return false;
	return recur3(A->left, B->right)&& recur3(A->right, B->left);
}


bool Solution::isSymmetric(TreeNode* root)
{
	if (root == nullptr)
		return true;
	return recur3(root->left, root->right);
}

int Solution::fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	int a = 0, b = 1, sum = 0;
	for (int i = 2; i <= n; i++)
	{
		sum = (a + b)%1000000007;				//8个0			1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内。
		a = b;
		b = sum;
	}
	return sum;

}

int Solution::numWays(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int a = 1, b = 1, sum = 0;				//与斐波那契数列不同处在于    n(0)=0/1
	for (int i = 2; i <= n; i++)
	{
		sum = (a + b) % 1000000007;				//8个0			1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内。
		a = b;
		b = sum;
	}
	return sum;

}

int Solution::maxProfit(vector<int>& prices)
{
	if (prices.empty())
		return 0;
	int maxP = 0;
	int tempP = 0;
	for (int i = 0; i < prices.size()-1; i++)
	{
		tempP += (prices[i+1] - prices[i]);
		tempP = max(0, tempP);
		maxP = max(tempP, maxP);
	}
	return maxP;

	//题解：动态规划
	//int cost = INT_MAX, profit = 0;			
	//for (int price : prices) {
	//	cost = min(cost, price);						//cost：最低价格的一天
	//	profit = max(profit, price - cost);		//当前天价格-最低价格      比较      n-1天的最大利润
	//																前 i 日最大利润 dp[i]等于前 i - 1日最大利润 dp[i-1] 和第i日卖出的最大利润中的最大值。
	//}
	//return profit;


}
int Solution::maxSubArray(vector<int>& nums)
{
	int res = nums[0];
	int temp = nums[0];					
	for (int i = 1; i < nums.size(); i++)
	{
		if (temp > 0)					//状态转移方程			temp(之前的和)如果大于0，则继续加上今天。反之，temp从今天开始
			temp += nums[i];
		else
			temp = nums[i];
		res = max(res, temp);		//比较所有局部最大
	}
	return res;

}

int Solution::maxValue(vector<vector<int>>& grid)
{
	//状态转移方程				f(i, j) = max[f(i, j−1), f(i−1, j)] + grid(i, j)			//第一行或第一列时，无需比较
	//左边来的与上面来的  的最大价值，加上当前格价值

	//空间复杂度降低：
	//	由于 dp[i][j]dp[i][j] 只与 dp[i - 1][j]dp[i−1][j], dp[i][j - 1]dp[i][j−1], grid[i][j]grid[i][j] 有关系，因此可以将原矩阵 gridgrid 用作 dpdp 矩阵，即直接在 gridgrid 上修改即可。
	//	应用此方法可省去 dpdp 矩阵使用的额外空间，因此空间复杂度从 O(MN)O(MN) 降至 O(1)O(1) 。

	//自己写
	int res = 0;
	for (int i = 0; i < grid.size(); i++)				//行
	{
		for (int j = 0; j < grid[0].size(); j++)		//列
		{
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				grid[i][j] += grid[i][j - 1];
			else if (j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid[grid.size() - 1][grid[0].size() - 1];
}

int Solution::translateNum(int num)
{
	string s = to_string(num);
	int a = 1, b = 1, c = 0;
	for (int i = 2; i <= s.size(); i++)			//这里要取<=      比如：size=2时，需要循环一次，所以需要<=size
	{
		string temp = s.substr(i - 2, 2);
		if (temp.compare("10") >= 0 && temp.compare("25") <= 0)
			c = a + b;
		else
			c = b;				//这里和例解的a  b是相反的
		a = b;
		b = c;
	}
	return b;

}

int Solution::lengthOfLongestSubstring(string s)
{
	unordered_map<char, int>m;				//key：字符			value：字符在m中的索引
	int temp = 0, res = 0, left = -1;			//temp记录至今的无重复子串长度即可
	for (int i = 0; i < s.size(); i++)
	{
		if (m.find(s[i]) == m.end())				//left表示上一个相同元素的索引，找不到则返回-1
			left = -1;
		else
			left = m[s[i]];
		m[s[i]] = i;					//将哈希表中代表的索引更新
		if (temp<i-left)				//动态规划：left在上一个dp的左边时，dp++
		{
			temp++;
		}
		else
		{
			temp = i - left;			//反之，dp为左右索引的差
		}
		res = max(temp, res);
	}
	return res;
}

void Solution::LNprint(ListNode* head)
{
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}


ListNode* Solution::deleteNode(ListNode* head, int val) 
{
	if (head->val == val)
		return head->next;
	ListNode* temp = head;
	while (temp != nullptr)
	{
		if (temp->next->val == val)
		{
			temp->next = temp->next->next;
			break;
		}
		temp = temp->next;
	}
	return head;

}

ListNode* Solution::getKthFromEnd(ListNode* head, int k)
{
	ListNode* pre = head;
	ListNode* cur = pre;
	for (int i = 0; i < k; i++)
	{
		cur = cur->next;
	}
	while (cur != nullptr)
	{
		pre = pre->next;
		cur = cur->next;
	}
	return pre;

}