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
    int widthOfBinaryTree(TreeNode* root) {

        if(!root) return 0;
        int ans = 0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        

        while(!q.empty()){
            int size = q.size();
            int minn = q.front().second;
            int last,first;
            

            for(int i = 0;i<size;i++){
                auto it = q.front();
                   q.pop();

                   TreeNode* node = it.first;

                   int curr = it.second-minn;
                   if(node->left)q.push({node->left,1LL*curr*2+1});
                    if(node->right)q.push({node->right,1LL*curr*2+2});
                    if(i == 0) first = curr;
                   if(i == size-1) last = curr;



            }
          

  ans = max(ans,last-first+1);

        }


    return ans;    
    }
};