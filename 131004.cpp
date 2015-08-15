#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict)
{
	vector<bool> cache(s.size(),0);
	if(dict.find(string(s,0,1))!=dict.end())
		cache[0]=1;

	for(int i=1; i<s.size(); ++i)
		for(int j=i-1; j>=0; --j)
			if(dict.find(string(s,0,i+1))!=dict.end())
				cache[i]=1;
			else if(cache[j])
			{
				string tmp(s,j+1,i-j);
				if(dict.find(tmp)!=dict.end())
				{
					cache[i] = 1;
					break;
				}
			}

	return cache[s.size()-1];
}

int main()
{
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");

	bool result = wordBreak("leetcode", dict);
	cout << result << endl;
	return 0;
}
