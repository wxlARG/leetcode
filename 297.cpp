#include"common.h"
using namespace std;

class Codec_solution1 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len=q.size();
            for(int i=0; i<len; ++i) {
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL) {
                    res+="# ";
                } else {
                    res+=to_string(node->val)+" ";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root=NULL;
        queue<TreeNode**> q;
        q.push(&root);
        stringstream ss(data);
        string word;
        while(ss>>word) {
            auto node=q.front();
            q.pop();
            if(word=="#") {
                *node=NULL;
            } else {
                *node=new TreeNode(stoi(word));
                q.push(&((*node)->left));
                q.push(&((*node)->right));
            }
        }
        return root;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize_helper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }
private:
    void serialize_helper(TreeNode* root, string& res) {
        if(root==NULL) {
            res+="# ";
            return;
        }
        res+=to_string(root->val)+' ';
        serialize_helper(root->left, res);
        serialize_helper(root->right, res);
    }

    TreeNode* deserialize_helper(stringstream& ss) {
        TreeNode* node=NULL;
        string word;
        if(ss>>word) {
            if(word=="#") return node;
            node=new TreeNode(stoi(word));
            node->left=deserialize_helper(ss);
            node->right=deserialize_helper(ss);
        }
        return node;
    }
};


int main() {
    Codec codec;
    auto root = create_tree({"1","2","3","null","null","4","5"});
    auto str=codec.serialize(root);
    cout << str << endl;
    root=codec.deserialize(str);
    cout << root->val << "\t" << root->left->val << endl;
}
