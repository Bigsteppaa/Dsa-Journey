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
    int countNodes(TreeNode* root) {
        return count(root,0);
        
    }

   int count(TreeNode* root,int cnt){
      
  if(!root) return 0;

    cnt = 1;
    cnt += count(root->left,cnt);
    cnt += count(root->right,cnt);


return cnt;

   }

};