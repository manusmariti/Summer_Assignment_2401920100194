QUES SYMMETRIC TREE 
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;

        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};
QUES SERIALIZE AND DESERIALIZE BINARY TREE
class Codec {
public:

    // Serialize
    void preorder(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    // Deserialize
    TreeNode* buildTree(string &data, int &index) {

        if (index >= data.size())
            return NULL;

        if (data[index] == 'N') {
            index += 2;   // Skip "N,"
            return NULL;
        }

        string num = "";

        while (index < data.size() && data[index] != ',') {
            num += data[index];
            index++;
        }

        index++;   // Skip ','

        TreeNode* root = new TreeNode(stoi(num));

        root->left = buildTree(data, index);
        root->right = buildTree(data, index);

        return root;
    }

    TreeNode* deserialize(string data) {
        int index = 0;
        return buildTree(data, index);
    }
};
QUES CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL
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
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);
        int index = mp[rootValue];
        root->left = build(preorder, inorder, inStart, index - 1);
        root->right = build(preorder, inorder, index + 1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
