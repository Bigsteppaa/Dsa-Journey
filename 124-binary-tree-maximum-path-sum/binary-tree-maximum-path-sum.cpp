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
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        find(root,maxi);
        return maxi;
    }
    int find(TreeNode* root,int &maxi){
 if(!root) return 0;

 int ls = max(0,find(root->left,maxi));
 int rs = max(0,find(root->right,maxi));
 
  maxi = max(maxi,ls+rs+root->val);

return (max(ls,rs) + root->val);

    }
};