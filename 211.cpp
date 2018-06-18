#include"common.h"
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for(auto &ch: word) {
            if(!node->child[ch-'a']) node->child[ch-'a'] = new TrieNode();
            node = node->child[ch-'a'];
        }
        node->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(root, word, 0);
    }

private:
    TrieNode* root;
    bool helper(TrieNode* node, string& word, int pos) {
        for(int i=pos; i<word.size(); ++i) {
            if(word[i]!='.') {
                if(node->child[word[i]-'a']) node=node->child[word[i]-'a'];
                else return false;
            } else {
                for(auto &trie: node->child) {
                    if(!trie) continue;
                    if(helper(trie, word, i+1)) return true;
                }
                return false;
            }
        }
        return node->end;
    }
};

int main() {
    WordDictionary *obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;
}
