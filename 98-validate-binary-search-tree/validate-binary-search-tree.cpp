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
    bool isValidBST(TreeNode* root) {
      
        return check(root,LLONG_MIN,LLONG_MAX);
        
    }
    bool check(TreeNode* root,long long lb,long long hb){
        if(!root) return true;

          if(root->val <=lb || root->val >=hb ) return false;

         return  check(root->left,lb,root->val) &&
          check(root->right,root->val,hb);

          
          


    }
};