#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool helper(TreeNode* root, int& tmax, int& tmin) {
    tmax=tmin=root->val;
    if(root->left!=NULL) {
        int lmax=INT_MIN, lmin=INT_MAX;
        bool l=helper(root->left, lmax, lmin);
        tmin = min(root->val, lmin);
        if(root->val<=lmax || !l) return false;
    }
    if(root->right!=NULL) {
        int rmax=INT_MIN, rmin=INT_MAX;
        bool r=helper(root->right, rmax, rmin);
        tmax = max(root->val, rmax);
        if(root->val>=rmin || !r) return false;
    }
    return true;
}

bool isValidBST(TreeNode* root) {
    if(root==NULL) return true;
    int max, min;
    return helper(root, max, min);
}

int main() {
    cout << isValidBST(create_tree({"2", "1", "3"})) << endl;
    cout << isValidBST(create_tree({"1", "2", "3"})) << endl;
    cout << isValidBST(create_tree({"1", "null", "1"})) << endl;
    cout << isValidBST(create_tree({"-2147483648", "null", "2147483647"})) << endl;
}
