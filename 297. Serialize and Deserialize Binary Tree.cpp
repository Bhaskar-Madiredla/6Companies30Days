/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Codec {
public:
    void f(TreeNode* root, string& s) { 
        if (root == NULL) {
            s += "n,"; 
            return;
        }
        s += to_string(root->val) + ","; 
        f(root->left, s); 
        f(root->right, s); 
    }

    string serialize(TreeNode* root) {
        string s;
        f(root, s);
        return s;
    }

    int inx = 0;
    TreeNode* deserialize(string data) {
        if (inx >= data.length()) return NULL;

        if (data[inx] == 'n') { 
            inx += 2; 
            return NULL;
        }

        int val = 0;
        bool negative = false;
        if (data[inx] == '-') { 
            negative = true;
            inx++;
        }
        while (inx < data.length() && data[inx] != ',') {
            val = val * 10 + (data[inx] - '0');
            inx++;
        }
        if (negative) val = -val;
        inx++; 

        TreeNode* root = new TreeNode(val);
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
