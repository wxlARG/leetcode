#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int minDepth(TreeNode* root) {
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    else if(root->left==NULL) return minDepth(root->right)+1;
    else if(root->right==NULL) return minDepth(root->left)+1;
    else return min(minDepth(root->left), minDepth(root->right))+1;
}

int main() {
    cout << minDepth(create_tree({"3", "9", "20", "null", "null", "15", "7"})) << endl;
    cout << minDepth(create_tree({"1", "2"})) << endl;
}
