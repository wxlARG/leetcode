#include"common.h"
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        nx=root;
        while(nx && nx->left) {
            s.push(nx);
            nx=nx->left;
        }
        cur=NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(nx) return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        cur=nx;
        if(nx->right==NULL && s.empty()) {
            nx=NULL;
        } else {
            if(nx->right) {
                nx=nx->right;
                while(nx->left) {
                    s.push(nx);
                    nx=nx->left;
                }
            } else {
                nx=s.top();
                s.pop();
            }
        }
        return cur->val;
    }
private:
    TreeNode* cur;
    TreeNode* nx;
    stack<TreeNode*> s;
};

int main() {
    TreeNode *root = create_tree({"4", "2", "6", "1", "3", "5", "NULL"});
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << "\t";
    cout << endl;
}
