QUES SAME TREE
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)
        return(p==q);
        return (p->val==q->val)
        && isSameTree(p->left,q->left)
        && isSameTree(p->right,q->right);
    }
};
QUES MAXIMUM DEPTH OF BINARY TREE
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //agr koi child node nhi hogi
        if(root==NULL)return 0;
        //root ke left me and then so on
        int l=maxDepth(root->left);
        //root ke right me and then so on
        int r=maxDepth(root->right);
        //return 1 because of root node 
        return 1+max(l,r);
    }
};
QUES INVERT BINARY TREE
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
