#include "Solution.h"


bool Solution::hasPathSum(TreeNode* root, int targetSum)
{
    //bfs
    //if (root == nullptr)return false;
    //queue<TreeNode*>qnode;
    //queue<int>qsum;
    //qnode.push(root);
    //qsum.push(root->val);
    //while (!qnode.empty())
    //{
    //    TreeNode* tnode = qnode.front();
    //    int tsum = qsum.front();
    //    qnode.pop(); qsum.pop();
    //    if (tnode->left == nullptr && tnode->right == nullptr)
    //    {
    //        if (tsum == targetSum)return true;
    //        continue;
    //    }
    //    if (tnode->left != nullptr)
    //    {
    //        qnode.push(tnode->left);
    //        qsum.push(tnode->left->val + tsum);
    //    }
    //    if (tnode->right != nullptr)
    //    {
    //        qnode.push(tnode->right);
    //        qsum.push(tnode->right->val + tsum);
    //    }
    //}
    //return false;

    //dfs
    if (root == nullptr)return false;
    if (root->left == nullptr && root->right == nullptr)return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val) ||
        hasPathSum(root->right, targetSum - root->val);

}

bool Solution::isPalindrome(string s)
{
    //原数组上更改
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))left++;
        while (left < right && !isalnum(s[right]))right--;
        if (left < right)
        {
            //cout << (char)tolower(s[left]) << "  " << (char)tolower(s[right]) << endl;
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
    }
    return true;


}

ListNode* Solution::reverseList(ListNode* head)
{
    ListNode* pre = head;
    ListNode* cur = nullptr;
    while (pre)
    {
        ListNode* temp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = temp;
    }
    return cur;
}

bool Solution::canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() > magazine.size())return false;
    vector<int>cnt(26);
    for (int i = 0; i < magazine.size(); i++)
    {
        cnt[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        cnt[ransomNote[i] - 'a']--;
        if (cnt[ransomNote[i] - 'a'] < 0)return false;
    }
    return true;
}

string Solution::addBinary(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    string res;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = carry;
        sum += a[i--] - '0';
        sum += b[j--] - '0';
        carry = sum / 2;
        res += to_string(sum % 2);
    }
  
    while (i >= 0)
    {
        int sum = carry + a[i--] - '0';
        carry = sum / 2;
        res += to_string(sum % 2);
    }
    while (j >= 0)
    {
        int sum = carry + b[j--] - '0';
        carry = sum / 2;
        res += to_string(sum % 2);
    }
    if (carry == 1)res += "1";
    
    reverse(res.begin(), res.end());
    
    return res;
}

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int>res;
    unordered_map<int, int>m;
    for (int i = 0; i < nums1.size(); i++)
    {
        if (m[nums1[i]] ==0)
        {
            m[nums1[i]]=1;
        }
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (m[nums2[i]] == 1)
        {
            res.push_back(nums2[i]);
            m[nums2[i]]++;
        }
    }


    return res;
}

int Solution::fib(int n)
{
    const int mod = 1e9 + 7;
    if (n == 0)return 0;
    if (n == 1)return 1;
    int a = 0, b = 1, sum;
    for (int i = 2; i <= n; i++)
    {
        sum = (a + b) % mod;
        a = b;
        b = sum;
    }
    return sum;
}
