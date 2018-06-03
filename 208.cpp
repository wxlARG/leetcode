#include"common.h"
using namespace std;

struct TrieStruct {
    char node;
    vector<TrieStruct*> child;
    bool end;
    TrieStruct(char n=-1): node(n), child(26, NULL), end(false){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieStruct();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieStruct* p=root;
        for(auto &c: word) {
            if(p->child[c-'a']==NULL) p->child[c-'a'] = new TrieStruct(c-'a');
            p=p->child[c-'a'];
        }
        p->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieStruct* p=root;
        for(auto &c: word) {
            if(p->child[c-'a']==NULL) return false;
            p=p->child[c-'a'];
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieStruct* p=root;  
        for(auto &c: prefix) {
            if(p->child[c-'a']==NULL) return false;
            p=p->child[c-'a'];
        }
        return true;
    }
private:    
    TrieStruct* root;
};

int main() {
	Trie* obj = new Trie();
	obj->insert("abcdefg");
	cout << obj->search("abcdefg") << endl;
	cout << obj->startsWith("abc") << endl;
}
