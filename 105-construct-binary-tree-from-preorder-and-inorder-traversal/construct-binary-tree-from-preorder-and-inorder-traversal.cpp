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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mp;
        for(int i = 0;i<preorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = build(preorder,0,preorder.size()-1,
        inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* build(vector<int>& preorder,int pst,int pend, vector<int>& inorder,int ist,int iend,map<int,int>& mp){

          if(pst>pend || ist>iend) return NULL;
     
     TreeNode* root = new TreeNode(preorder[pst]);
     
     int irt = mp[preorder[pst]];
     int lefts = irt-ist;



      root->left = build(preorder,pst+1,pst+lefts,inorder,ist,irt-1,
      mp);
       root->right = build(preorder,pst+lefts+1,pend,inorder,irt+1,iend,
      mp);

 
        return root;
    }
};