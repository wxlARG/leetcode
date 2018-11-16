#include"common.h"
using namespace std;

struct Node {
    int pos;
    vector<Node*> next;
    Node(): pos(-1), next(26, NULL) {}
};

void buildTrie(string& str, int pos, Node* root) {
    Node* node=root;
    for(auto c: str) {
        if(node->next[c-'a']!=NULL) {
            node=node->next[c-'a'];
        } else {
            Node* tmp=new Node();
            node->next[c-'a']=tmp;
            node=tmp;
        }
    }
    node->pos=pos;
}

void dfs(Node* node, int pos, string& cache, vector<vector<int>>& res) {
    if(node->pos!=-1 && node->pos!=pos) {
        int i=0, j=cache.size()-1;
        for(; i<j; ++i, --j) if(cache[i]!=cache[j]) break;
        if(i>=j) res.push_back({node->pos, pos});
    }
    for(int i=0; i<node->next.size(); ++i) {
        if(node->next[i]==NULL) continue;
        cache.push_back(i+'a');
        dfs(node->next[i], pos, cache, res);
        cache.pop_back();
    }
}

void helper(Node* root, string& str, int pos, vector<vector<int>>& res) {
    Node* node=root;
    for(int i=str.size()-1; i>=0; --i) {
        if(node->pos!=-1 && node->pos!=pos) {
            int j=0, k=i;
            for(; j<k; ++j, --k) if(str[j]!=str[k]) break;
            if(j>=k) res.push_back({node->pos, pos});
        }
        if(node->next[str[i]-'a']==NULL) return;
        node=node->next[str[i]-'a'];
    }
    string cache;
    dfs(node, pos, cache, res);
}

vector<vector<int>> palindromePairs_solution1(vector<string>& words) {
    Node* root=new Node();
    for(int i=0; i<words.size(); ++i) buildTrie(words[i], i, root);
    vector<vector<int>> res;
    for(int i=0; i<words.size(); ++i) helper(root, words[i], i, res);
    return res;
}

bool isPalindrome(string& str) {
    for(int start=0, end=str.size()-1; start<end; ++start, --end) {
        if(str[start]!=str[end]) return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> dict;
    vector<vector<int>> res;
    for(int i=0; i<words.size(); ++i) {
        auto str=words[i];
        reverse(str.begin(), str.end());
        dict[str]=i;
    }
    for(int i=0; i<words.size(); ++i) {
        for(int j=0; j<=words[i].size(); ++j) {
            string left=words[i].substr(0, j), right=words[i].substr(j);
            auto ileft=dict.find(left), iright=dict.find(right);
            if(ileft!=dict.end() && isPalindrome(right) && ileft->second!=i) res.push_back({i, ileft->second});
            if(!left.empty() && iright!=dict.end() && isPalindrome(left) && iright->second!=i) res.push_back({iright->second, i});
        }
    }
    return res;
}

int main() {
    //vector<string> words={"abcd","dcba","lls","s","sssll"};
    vector<string> words={"a","abc","aba",""};
    auto res=palindromePairs(words);
    for(auto& pos: res) cout << pos[0] << "," << pos[1] << endl;
}
