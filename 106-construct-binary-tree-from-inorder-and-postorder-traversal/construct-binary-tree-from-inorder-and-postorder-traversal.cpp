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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0;i<inorder.size();i++) mp[inorder[i]] = i;
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }

    TreeNode* build(vector<int>& inorder,int ist,int iend, vector<int>& postorder,int pst,int pend ,unordered_map<int,int>& mp){

  if(ist>iend || pst>pend) return NULL;

  TreeNode* root = new TreeNode(postorder[pend]);
  int irt = mp[root->val];
  int left = irt-ist;

  root->left = build(inorder,ist,irt-1,postorder,pst,pst+left-1,mp);
  root->right = build(inorder,irt+1,iend,postorder,pst+left,pend-1,mp);

return root;
    }


};