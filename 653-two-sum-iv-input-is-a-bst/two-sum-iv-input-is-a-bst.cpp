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
    bool findTarget(TreeNode* root, int k) {
           unordered_set<int> set;
           int flag = 0;
        while(root){
        if(!root->left){
           
            if(set.count(k - root->val)) flag = 1;
               set.insert(root->val);
                root = root->right;
        }
        else{
          TreeNode* prev = root->left;

          while(prev->right && prev->right != root) prev = prev->right;
            
            if(prev->right == root){
                prev->right = NULL;
                 if(set.count(k - root->val)) flag = 1;
               set.insert(root->val);
                root = root->right;
            }
            else{
                prev->right = root;
                root = root->left;
            }
        }

        }
        return flag;
        
    }
};