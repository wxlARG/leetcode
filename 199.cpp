#include"common.h"
using namespace std;

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int q_size=q.size();
        res.push_back(q.front()->val);
        for(int i=0; i<q_size; ++i) {
            TreeNode* node=q.front();
            q.pop();
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
    }
    return res;
}

int main() {
    auto res=rightSideView(create_tree({"1", "2", "3", "null", "5", "null", "4"}));
    for(auto &v: res) cout << v << "\t";
    cout << endl;
}
