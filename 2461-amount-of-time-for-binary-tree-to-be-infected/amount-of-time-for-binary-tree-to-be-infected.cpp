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

         TreeNode* mark(unordered_map<TreeNode*,TreeNode*>& mp,TreeNode* root,int st){

                TreeNode* need = NULL;
                queue<TreeNode*> q;
                q.push(root);
                while(!q.empty()){

                  TreeNode* temp = q.front(); q.pop();
                  if(temp->val == st) need = temp;
                    if(temp->left){
                        q.push(temp->left);
                        mp[temp->left] = temp;
                    }
                      if(temp->right){
                        q.push(temp->right);
                        mp[temp->right] = temp;
                    }
                    
                }
return need;
         }
    int amountOfTime(TreeNode* root, int start) {

            unordered_map<TreeNode*,TreeNode*> mp;

        TreeNode* node = mark(mp,root,start);

          return getans(mp,node);
        
    }
    int getans(unordered_map<TreeNode*,TreeNode*>& mp,TreeNode* node){

          unordered_map<TreeNode*,bool> vis;
          queue<TreeNode*> q;
          q.push(node);
          vis[node] = true;
          int maxi = 0;

          while(!q.empty()){

           int size = q.size();
           int af = 0;
                
                for(int i = 0;i<size;i++){
                          TreeNode* temp = q.front();q.pop();
                          if(temp->left && !vis[temp->left]){

                            q.push(temp->left);
                            vis[temp->left] = true;
                            af = 1;
                          }
                          if(temp->right && !vis[temp->right]){

                            q.push(temp->right);
                            vis[temp->right] = true;
                            af = 1;
                          }
                          if(mp.count(temp) && !vis[mp[temp]]){

                            q.push(mp[temp]);
                            vis[mp[temp]] = true;
                            af = 1;
                          }
                              
                }
                if(af) maxi++;

          } 
               return maxi;
    }
};