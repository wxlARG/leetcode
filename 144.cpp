#include"common.h"
using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    vector<TreeNode*> s;
    TreeNode* node=root;
    while(node!=NULL || s.size()!=0) {
        if(node==NULL) {
            node=s.back();
            s.pop_back();
            node=node->right;
        } else {
            res.push_back(node->val);
            s.push_back(node);
            node=node->left;
        }
    }
    return res;
}

int main() {
    auto root = create_tree({"1", "null", "2", "3"});
    auto res=preorderTraversal(root);
    for(auto &v: res) cout << v << "\t";
    cout << endl;
}
