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
        class Gettree {
            public:
                 stack<TreeNode*> st;
                 bool flag = true;

                 Gettree(TreeNode* root,bool isr){
                     flag = isr;
                    pushall(root,flag);
                   
                 }

                 bool hasnext(){
                    return !st.empty();
                 }

                 int next(){
                   TreeNode* node = st.top();
                   st.pop();
                   if(!flag) pushall(node->right,flag);
                   else pushall(node->left,flag);


                      return node->val;

                 }

                 private:
                 void pushall(TreeNode* node,bool flag){
                    if(!flag) for(;node != NULL;st.push(node),node=node->left);
                    else for(;node != NULL;st.push(node),node=node->right);

                 }

                
        } ;


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        Gettree  r(root,true);
        Gettree l(root,false);

        int left = l.next();
        int right = r.next();

        while(left<right){
          if(left+right == k) return true;
          else if(left+right>k){ if(r.hasnext())right = r.next(); else break; }
          else{ if(l.hasnext()) left = l.next();
          else break;
          }
        }
      return false;  
    }
};