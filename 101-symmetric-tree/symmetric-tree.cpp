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
    bool isSymmetric(TreeNode* root) {

        return (root == NULL || chk(root->left,root->right));
        
    }

    bool chk(TreeNode* left,TreeNode* right){
      if(left == NULL || right == NULL) return left == right;

      if(left->val != right->val) return false;

      return chk(left->right,right->left) && chk(left->left,right->right);
       
    }
};