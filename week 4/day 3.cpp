QUESTION 1 : SEARCH IN A BINARY SEARCH TREE
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            root = val < root->val? root->left : root->right; 
        }
        return root;
    }
};

QUESTION 2 : VALIDATE BINARY SEARCH TREE
class Solution {
public:
    bool solve(TreeNode* root, long long low, long long high) {
        if (root == nullptr)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
Question 3 : LOWEST COMMON ANCESTOR OF BST 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int current = root->val;
        if(current < p->val && current < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(current > p->val && current > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return root;
    }
};
  

