#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L)
{
	int Llen = L[0].size();
	vector<int> result;
	map<string, vector<int> > rmap;
	for(int i=0; i<L.size(); ++i)
	{
		map<string, vector<int> >::iterator it = rmap.find(L[i]);
		if(it == rmap.end())
		{
			vector<int> tmp(2,1);
			rmap.insert(pair<string, vector<int> >(L[i],tmp));
		}
		else
		{
			++it->second[0];
			++it->second[1];
		}
	}

	int zeronum = rmap.size();

	for(int i=0; i<S.size();++i)
	{
		string tmpstr(S,i,Llen);
		map<string, vector<int> >::iterator it = rmap.find(tmpstr);
		if(it == rmap.end())
			continue;

		int zerocount = zeronum;
		int j = i;
		for(;j<S.size(); j+=Llen)
		{
			tmpstr = string(S,j,Llen);
			it = rmap.find(tmpstr);
			if(it == rmap.end() || it->second[1] == 0)
				break;

			--it->second[1];

			if(it->second[1] == 0)
				--zerocount;

			if(zerocount == 0)
				break;
		}

		j+=Llen;

		if(zerocount == 0)
			result.push_back(i);

		if(j >= S.size())
			break;

		for(it = rmap.begin(); it!=rmap.end(); ++it)
			it->second[1] = it->second[0];
	}
	return result;
}

int main()
{
	vector<string> L;
	string arr[] = {"a","a"};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]);++i)
		L.push_back(arr[i]);

	string S = "aaa";

	vector<int> result = findSubstring(S,L);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
