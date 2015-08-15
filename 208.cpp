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
using namespace std;

/*class TrieNode {
	public:
		// Initialize your data structure here.
		TrieNode() {
			val = 0;
			flag = false;
			child = NULL;
			next = NULL;
		}

		TrieNode(char c) {
			val = c;
			flag = false;
			child = NULL;
			next = NULL;
		}

		char val;
		bool flag;
		TrieNode *child;
		TrieNode *next;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
		for(int i=0; i<s.size(); ++i)
		{
			if(p->child != NULL)
			{
				p = p->child;
				TrieNode *q = NULL;
				while(p!=NULL && p->val != s[i])
				{
					q=p;
					p=p->next;
				}

				if(p==NULL)
				{
					TrieNode *tmp = new TrieNode(s[i]);
					q->next = tmp;
					p=tmp;
				}
			}
			else
			{
				TrieNode *tmp = new TrieNode(s[i]);
				p->child = tmp;
				p = tmp;
			}
		}

		p->flag = 1;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
       TrieNode *p = root;
	   for(int i=0; i<key.size(); ++i)
	   {
		   p=p->child;
		   while(p!=NULL && p->val != key[i])
			   p=p->next;

		   if(p == NULL)
			   return false;
	   }

	   if(p->flag)
		   return true;
	   else
		   return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode *p = root;
		for(int i=0; i<prefix.size(); ++i)
		{
			p=p->child;
			while(p!=NULL && p->val != prefix[i])
				p=p->next;

			if(p==NULL)
				return false;
		}

		return true;
    }

private:
    TrieNode* root;
};*/

class TrieNode {
	public:
		// Initialize your data structure here.
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

		// Inserts a word into the trie.
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

		// Returns if the word is in the trie.
		bool search(string key) {
			TrieNode *node = root;
			for(int i=0; i<key.size(); ++i)
			{
				unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(key[i]);
				if(it == node->subtrie.end())
					return 0;

				node = it->second;
			}

			if(node->flag)
				return 1;
			else
				return 0;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			TrieNode *node = root;
			for(int i=0; i<prefix.size(); ++i)
			{
				unordered_map<char,TrieNode*>::iterator it = node->subtrie.find(prefix[i]);
				if(it == node->subtrie.end())
					return 0;

				node = it->second;
			}
			return 1;
		}

	private:
		TrieNode* root;
};

int main()
{
	Trie trie;
	trie.insert("key");
	bool result = trie.search("key");
	cout << result << endl;
	return 0;
}
