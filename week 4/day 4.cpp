QUESTION 1 : PATH SUM
class Solution {
public:
    bool inOrder(TreeNode* root, int sum, int& targetSum){
        if(root == NULL)
            return false;
            sum += root->val;
            if(root->left == NULL && root->right == NULL){
                if(sum == targetSum)
                return true;

            return false;
            }
            bool leftside = inOrder(root->left, sum, targetSum);
            bool rightside = inOrder(root->right, sum, targetSum);
            return leftside || rightside;
        }  
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool result = inOrder(root, sum, targetSum);
        return result;
        
    }
};
  
QUESTION 2 : DIAMETER OF THE BINARY TREE
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (node == NULL) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};
  
QUESTION 3 : BINARY TREE MAXIMUM PATH 
class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Maximum path passing through current node
        ans = max(ans, left + right + root->val);

        // Return maximum path extending to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
