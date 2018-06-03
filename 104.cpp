#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    cout << maxDepth(create_tree({"3", "9", "20", "null", "null", "15", "7"})) << endl;
}
