Question 1: Binary Tree Inorder Traversal

class Solution {
private :
void inorder(TreeNode* root, vector<int>& ans){
    if(root==NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

Question 2: Bianry Tree level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        } 
        return ans;
    }
};

Question 3 : Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToright = true;
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i = 0; i <size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                int index = (leftToright) ? i : (size- 1- i);
                row[index] = node->val;
                if(node->left){
                nodesQueue.push(node->left);
                }
                if(node->right){
                nodesQueue.push(node->right);
                }
            }
            leftToright = !leftToright;
        result.push_back(row);

        }
        return result;
    }
};
