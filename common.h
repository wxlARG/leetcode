#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<time.h> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(vector<int> nums) {
    if(nums.size()==0) return NULL;
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    for(int i=1; i<nums.size(); ++i) {
        ListNode *q = new ListNode(nums[i]);
        p->next = q;
        p = q;
    }
    return head;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_tree(vector<string> nums) {
    TreeNode* root=NULL;
    queue<TreeNode**> q;
    q.push(&root);
    for(auto &v: nums) {
        auto t=q.front();
        q.pop();
        if(v=="null" || v=="NULL") continue;
        *t=new TreeNode(stoi(v));;
        q.push(&(*t)->left);
        q.push(&(*t)->right);
    }
    return root;
}

string print_tree(TreeNode* t) {
    queue<TreeNode*> c;
    c.push(t);
    vector<string> res;
    while(!c.empty()) {
        auto v = c.front();
        c.pop();
        if(v!=NULL) {
            c.push(v->left);
            c.push(v->right);
            res.push_back(to_string(v->val));
        } else {
            res.push_back("null");
        }       
    }
    while(res.back()=="null") res.pop_back();
    string s="[";
    for(auto &v: res) s += v+",";
    s.pop_back();
    s+="]";
    return s;
}

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* create_tree_link(vector<string> nums) {
    TreeLinkNode* root=NULL;
    queue<TreeLinkNode**> q;
    q.push(&root);
    for(auto &v: nums) {
        auto t=q.front();
        q.pop();
        if(v=="null" || v=="NULL") continue;
        *t=new TreeLinkNode(stoi(v));;
        q.push(&(*t)->left);
        q.push(&(*t)->right);
    }
    return root;
}

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* createUndirectedGraphNode(vector<string> graph) {
    if(graph.size()==0) return NULL;
    unordered_map<int, UndirectedGraphNode*> cache;
    for(auto &c: graph) {
        if(c=="#") continue;
        if(cache.find(stoi(c))!=cache.end()) continue;
        cache[stoi(c)]=new UndirectedGraphNode(stoi(c));
    }
    bool is_first=true;
    UndirectedGraphNode* p=NULL;
    for(auto &c: graph) {
        if(c=="#") {
            is_first=true;
            continue;
        }
        if(is_first) {
            p=cache[stoi(c)];
            is_first=false;
            continue;
        }
        p->neighbors.push_back(cache[stoi(c)]);
    }
    return cache[stoi(graph[0])];
}

struct TrieNode {
    vector<TrieNode*> child;
    bool end;
    TrieNode(): child(26, NULL), end(false){}
};
