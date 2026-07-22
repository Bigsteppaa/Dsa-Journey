class Solution {
public:

    int ans = 0;

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        small(root, k, cnt);
        return ans;
    }

    void small(TreeNode* node, int k, int& cnt){

        if(!node) return;

        small(node->left, k, cnt);

        cnt++;

        if(cnt == k){
            ans = node->val;
            return;
        }

        small(node->right, k, cnt);
    }
};