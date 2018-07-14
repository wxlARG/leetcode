#include"common.h"
using namespace std;

void helper_solution1(TreeNode* root, vector<string>& res, string s) {
    s+=to_string(root->val)+"->";
    if(root->left==NULL && root->right==NULL) {
        res.push_back(s.erase(s.length()-2));
        return;
    }
    if(root->left!=NULL) helper_solution1(root->left, res, s);
    if(root->right!=NULL) helper_solution1(root->right, res, s);
}

vector<string> binaryTreePaths_solution1(TreeNode* root) {
    vector<string> res;
    if(root==NULL) return res;
    string s;
    helper_solution1(root, res, s);
    return res;
}

void helper(TreeNode* root, vector<string>& res, string s) {
    if(root->left==NULL && root->right==NULL) {
        res.push_back(s);
        return;
    } 
    s+="->";
    if(root->left!=NULL) helper(root->left, res, s+to_string(root->left->val)); 
    if(root->right!=NULL) helper(root->right, res, s+to_string(root->right->val)); 
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root==NULL) return res;
    string s(to_string(root->val));
    helper(root, res, s);
    return res;
}

int main() {
    auto res=binaryTreePaths(create_tree({"1", "2", "3", "null", "5"}));
    for(auto& s: res) cout << s << endl;
}
