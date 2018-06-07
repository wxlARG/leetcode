#include"common.h"
using namespace std;

int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int ll=0, lr=1, rr=0;
    for(auto p=root; p; p=p->left) ++ll;
    for(auto p=root; p; p=p->right) ++rr;
    if(ll==rr) return (1<<ll)-1;
    for(auto p=root->left; p; p=p->right) ++lr;
    if(lr==ll) return ((1<<(lr-1))-1)+1+countNodes(root->right);
    else return ((1<<(rr-1))-1)+1+countNodes(root->left);
}

int main() {
    cout << countNodes(create_tree({"1", "2", "3", "4", "5", "6"})) << endl;
}
