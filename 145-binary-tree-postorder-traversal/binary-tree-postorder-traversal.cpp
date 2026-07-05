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
    vector<int> postorderTraversal(TreeNode* root) {

     vector<int> ans;
     if(root == NULL) return ans;

     stack<TreeNode*> st;
     TreeNode* curr = root;
     

     while(!st.empty() || curr != NULL){

        if(curr != NULL){
            st.push(curr);
            curr = curr->left;

        }
        else {

         root = st.top()->right;


         if(root == NULL){

            root = st.top();st.pop();
            ans.push_back(root->val);

          while(!st.empty() && st.top()->right == root){
            root = st.top();st.pop();
           
            ans.push_back(root->val); 

          }

         }
         else curr = root;

        }


     }

     return ans;
        
    }
};