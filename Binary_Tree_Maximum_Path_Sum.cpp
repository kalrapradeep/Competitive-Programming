/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSum(TreeNode* root,int& max1)
    {
        if(!root)
            return 0;
        int Lmax=findSum(root->left,max1);
        int Rmax=findSum(root->right,max1);
        max1=max(max1,max(Lmax+Rmax+root->val,max(Lmax+root->val,max(root->val,Rmax+root->val))));
        return max(Lmax+root->val,max(Rmax+root->val,root->val));
    }
    int maxPathSum(TreeNode* root) {
        int max=INT_MIN;
        findSum(root,max);
        return max;
    }
};
