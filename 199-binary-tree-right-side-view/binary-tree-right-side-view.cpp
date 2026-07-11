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
    vector<int> rightSideView(TreeNode* root) {

vector<int> ans;

rec(root,0,ans);
return ans;
    }

    void rec(TreeNode* node,int lvl , vector<int>& ans){

          if(!node) return;

          if(ans.size() == lvl)ans.push_back(node->val);
          rec(node->right,lvl+1,ans);
          rec(node->left,lvl+1,ans);

    }
};