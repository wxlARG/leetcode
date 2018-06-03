#include"common.h"
using namespace std;

vector<int> postorderTraversal_solution1(TreeNode* root) {
    vector<int> res;
    vector<pair<TreeNode*, bool>> s;
    TreeNode* node=root;
    while(node!=NULL || s.size()!=0) {
        if(node==NULL) {
            if(s.back().second) {
                res.push_back(s.back().first->val);
                s.pop_back();
            } else {
                s.back().second=true;
                node=s.back().first->right;
            }
        } else {
            s.push_back({node, false});
            node=node->left;
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* node=root, *last_node=NULL;
    while(node!=NULL || !s.empty()) {
        if(node==NULL) {
            auto top_node=s.top();
            if(top_node->right && last_node!=top_node->right) {
                node=top_node->right;
            } else {
                res.push_back(top_node->val);
                last_node=top_node;
                s.pop();
            }
        } else {
            s.push(node);
            node=node->left;
        }
    }
    return res;
}

int main() {
    auto root = create_tree({"3", "1", "2"});
    auto res=postorderTraversal(root);
    for(auto &v: res) cout << v << "\t";
    cout << endl;
}
