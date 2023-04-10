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
