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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root) return NULL;
       if(root->val == key) return helper(root);
       TreeNode*  dummy = root;
       while(root){

       if(root->val>key){
        if(root->left && root->left->val == key){
            root->left = helper(root->left);
            break;
        }else
            root = root->left;
       }

        else{
            if(root->right && root->right->val == key){
            root->right = helper(root->right);
            break;
        }else
            root = root->right;
        }
        

        }

          return dummy;
        }

        TreeNode* helper(TreeNode* node){

           if(!node->left) return node->right;
           else if(!node->right) return node->left;

           TreeNode* rc = node->right;
           TreeNode* mostr = findR(node->left);
           mostr->right = rc;

           return node->left;
        }

        TreeNode* findR(TreeNode* node){
             if(!node->right) return node; 

             return findR(node->right);


        }
       
        
    
};