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
#include<unordered_map>
using namespace std;

void func(vector<string>& result, vector<string>& tmpstr, unordered_map<int,vector<int> >& map, string& s, int pos)
{
	if(pos<0)
	{
		string res;
		for(int i=tmpstr.size()-1; i>=0; --i)
			res += tmpstr[i] + " ";
		res.pop_back();
		result.push_back(res);
		return;
	}

	unordered_map<int,vector<int> >::iterator iter = map.find(pos);
	if(iter == map.end())
		return;

	for(int i=0; i<iter->second.size(); ++i)
	{
		tmpstr.push_back(string(s,iter->second[i],pos-iter->second[i]+1));
		func(result,tmpstr,map,s,iter->second[i]-1);
		tmpstr.pop_back();
	}
}

vector<string> wordBreak(string s, unordered_set<string> &dict)
{
	vector<string> result;

	vector<int> tmp;
	unordered_map<int,vector<int> > map;

	if(dict.find(string(s,0,1))!=dict.end())
	{
		tmp.push_back(0);
		map[0]=tmp;
	}

	for(int i=1; i<s.size(); ++i)
	{
		tmp.clear();
		if(dict.find(string(s,0,i+1))!=dict.end())
			tmp.push_back(0);

		for(int j=0; j<i; ++j)
		{
			unordered_map<int,vector<int> >::iterator iter = map.find(j);
			if(iter!=map.end() && dict.find(string(s,j+1,i-j))!=dict.end())
				tmp.push_back(j+1);
		}
		map[i]=tmp;
	}

	vector<string> tmpstr;
	func(result,tmpstr,map,s,s.size()-1);
	return result;
}

int main()
{
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");

	vector<string> result = wordBreak("catsanddog", dict);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
