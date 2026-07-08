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
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        mex(mx,root);
        return mx;
        
    }


   int mex(int &maxx,TreeNode* root ){

  if(root == NULL) return 0;
  int lh = mex(maxx,root->left);
  int rh = mex(maxx,root->right);
   maxx = max(maxx,lh + rh);
   
   return 1 + max(lh,rh);
       
    }


};