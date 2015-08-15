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

struct Trie{
	unordered_map<char, Trie*> *child;
	bool endflag;
	Trie(){
		endflag = 0;
		child = new unordered_map<char, Trie*>();
	}
};

class WordDictionary {
public:
	void addWord(string word) {
		unordered_map<char, Trie*> *level = &tree;
		for(int i=0; i<word.size(); ++i)
		{
			unordered_map<char, Trie*>::iterator it = level->find(word[i]);
			if(it == level->end())
			{
				Trie* tmp = new Trie();
				if(i==word.size()-1)
					tmp->endflag = 1;

				level->insert(make_pair(word[i],tmp));
				level = tmp->child;
			}
			else
				level = it->second->child;
		}
	}

	bool search(string word) {
		subsearch(&tree, word, 0, false);
	}

private:
	unordered_map<char, Trie*> tree;

	bool subsearch(unordered_map<char, Trie*> *level, string& word, int pos, bool lastflag)
	{
		if(pos == word.size()) 
			return lastflag;

		if(word[pos] != '.')
		{
			unordered_map<char, Trie*>::iterator it = level->find(word[pos]);
			if(it == level->end())
				return false;
			lastflag = it->second->endflag;
			level = it->second->child;
			subsearch(level, word, pos+1,lastflag);
		}
		else
		{
			for(unordered_map<char, Trie*>::iterator it=level->begin(); it!=level->end(); ++it)
			{
				lastflag = it->second->endflag;
				level = it->second->child;
				if(subsearch(level, word, pos+1, lastflag))
					return true;
			}
		}
	}
};

int main()
{
	WordDictionary wd;
	wd.addWord("a");
	wd.addWord("ab");
	cout << wd.search("a") << endl;
	cout << wd.search("a.") << endl;
	cout << wd.search("ab") << endl;
	cout << wd.search(".a") << endl;
	cout << wd.search(".b") << endl;
	cout << wd.search("ab.") << endl;
	cout << wd.search(".") << endl;
	cout << wd.search("..") << endl;
	return 0;
}
