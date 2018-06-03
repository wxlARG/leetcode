#include"common.h"
using namespace std;

class Trie {
    public:
        Trie() {
            root = new TrieNode();    
        }
        void add_word(string& word) {
            TrieNode* p=root;
            for(auto& ch: word) {
                if(!p->child[ch-'a']) p->child[ch-'a'] = new TrieNode();
                p = p->child[ch-'a'];
            }
            p->end=true;
        }
        TrieNode* get_root() {
            return root;
        }
    private:
        TrieNode* root;
};

void dfs(vector<vector<char>>& board, int x, int y, unordered_set<string>& cache, string& str, TrieNode* node) {
    if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]==0) return;
    char ch=board[x][y];
    if(!node->child[ch-'a']) return;
    node = node->child[ch-'a'];
    str.push_back(ch);
    if(node->end) cache.insert(str);
    board[x][y] = 0;
    vector<pair<int, int>> dirs={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for(auto &dir: dirs) dfs(board, x+dir.first, y+dir.second, cache, str, node);
    board[x][y] = ch;
    str.pop_back();
} 

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for(auto& word: words) trie.add_word(word);
    auto root = trie.get_root();
    unordered_set<string> cache;
    string str;
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) {
            dfs(board, i, j, cache, str, root);
        }
    }
    vector<string> res;
    for(auto &s: cache) res.push_back(s);
    return res;
}

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    auto res = findWords(board, words);
    for(auto& str: res) cout << str << endl;
}
