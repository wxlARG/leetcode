#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class TrieNode {
	public:
		TrieNode() {
			flag = 0;
		}

		bool flag;
		unordered_map<char,TrieNode*> subtrie;
};

class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		void insert(string s) {
			TrieNode *node = root;
			for(int i=0; i<s.size(); ++i)
			{
				unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(s[i]);
				if(it == node->subtrie.end())
				{
					TrieNode *tmp = new TrieNode();
					node->subtrie.insert(make_pair(s[i],tmp));
					node = tmp;
				}
				else
					node = it->second;
			}
			node->flag = 1;
		}

		TrieNode* root;
};

void dfs(vector<vector<char> >& board, TrieNode* node, vector<string>& result, vector<vector<bool> >& color, string& tmp, int x, int y)
{
	tmp.push_back(board[x][y]);
	color[x][y] = 1;

	if(node->flag)
	{
		node->flag = 0;
		result.push_back(tmp);
	}

	if(x-1>=0 && color[x-1][y]==0)
	{
		unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(board[x-1][y]);
		if(it != node->subtrie.end())
			dfs(board,it->second,result,color,tmp,x-1,y);
	}

	if(x+1<board.size() && color[x+1][y]==0)
	{
		unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(board[x+1][y]);
		if(it != node->subtrie.end())
			dfs(board,it->second,result,color,tmp,x+1,y);
	}

	if(y-1>=0 && color[x][y-1]==0)
	{
		unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(board[x][y-1]);
		if(it != node->subtrie.end())
			dfs(board,it->second,result,color,tmp,x,y-1);
	}

	if(y+1<board[0].size() && color[x][y+1]==0)
	{
		unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(board[x][y+1]);
		if(it != node->subtrie.end())
			dfs(board,it->second,result,color,tmp,x,y+1);
	}

	color[x][y] = 0;
	tmp.pop_back();
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words)
{
	vector<string> result;
	Trie trie;
	for(int i=0; i<words.size(); ++i)
		trie.insert(words[i]);

	vector<vector<bool> > color(board.size(), vector<bool>(board[0].size(), 0));
	TrieNode* p = trie.root;

	for(int i=0; i<board.size(); ++i)
	{
		for(int j=0; j<board[i].size(); ++j)
		{
			string tmp;
			unordered_map<char,TrieNode*>::iterator it = p->subtrie.find(board[i][j]);
			if(it == p->subtrie.end())
				continue;

			dfs(board,it->second,result,color,tmp,i,j);
		}
	}
	return result;
}

int main()
{
	char c[][4] = {
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};

	string a[] = {"oath","pea","eat","rain"};

	vector<string> words;
	for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
		words.push_back(a[i]);

	vector<vector<char> > board;
	for(int i=0; i<7; ++i)
	{
		vector<char> tmp;
		for(int j=0; j<6; ++j)
			tmp.push_back(c[i][j]);
		board.push_back(tmp);
	}

	vector<string> result = findWords(board,words);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
