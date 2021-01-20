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
    TreeNode* findMax(TreeNode* root)
    {
        if(!root)
            return NULL;
        TreeNode* temp1=findMax(root->left);
        TreeNode* temp2=findMax(root->right);
        if(temp1!=NULL&&temp1->val>root->val)
        {
            if(temp2&&temp2->val>temp1->val)
            return temp2;
            else
                return temp1;
        }
        else if(temp2!=NULL&&temp2->val>root->val)
        {
            if(temp1&&temp1->val>temp2->val)
            return temp1;
            return temp2;
        }
        else
        {
            return root;
        }
    }
    TreeNode* findMin(TreeNode* root)
    {
        if(!root)
            return NULL;
        TreeNode* temp1=findMin(root->left);
        TreeNode* temp2=findMin(root->right);
        if(!temp1&&!temp2)
            return root;
        if(temp1!=NULL&&temp1->val<root->val)
        {
            if(temp2&&temp1->val>temp2->val)
            return temp2;
            else
                return temp1;
        }
        else if(temp2!=NULL&&temp2->val<root->val)
        {
            if(temp1&&temp2->val>temp1->val)
            return temp1;
            return temp2;
        }
        else
        {
            return root;
        }
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        TreeNode* temp1=findMax(root->left);
        TreeNode* temp2=findMin(root->right);
        if(temp1!=NULL&&root->val<temp1->val)
        {
            if(temp2==NULL||root->val<temp2->val)
            {
                int temp=root->val;
                root->val=temp1->val;
                temp1->val=temp;
            }
            else
            {
                int temp=temp2->val;
                temp2->val=temp1->val;
                temp1->val=temp;
            }
            
            
        }
        else if(temp2!=NULL&&root->val>temp2->val)
        {
                int temp=root->val;
                root->val=temp2->val;
                temp2->val=temp;
            return;
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
};
