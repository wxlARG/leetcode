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

bool func(string& s, int start, int end)
{
	while(start < end)
		if(s[start++] != s[end--])
			return false;
	return true;
}

vector<vector<string> > partition(string s)
{
	vector<vector<string> > result;
	if(s.size()==0)
		return result;

	vector<vector<bool> > cache(s.size(), vector<bool>(s.size(),0));
	for(int i=0; i<s.size(); ++i)
		for(int j=0; j<s.size()-i; ++j)
			if(i==0)
				cache[j][j+i] = 1;
			else if(i==1 && s[j]==s[j+i])
				cache[j][j+i] = 1;
			else if(s[j]==s[j+i])
				cache[j][j+i] = cache[j+1][j+i-1];

	vector<int> tmp;
	vector<vector<int> > poscache;
	unordered_map<int,vector<vector<int> > > map;
	tmp.push_back(0);
	poscache.push_back(tmp);
	map[0]=poscache;

	for(int i=1; i<s.size(); ++i)
	{
		poscache.clear();
		for(int j=0; j<=i; ++j)
		{
			if(cache[j][i])
			{
				if(j>0)
				{
					vector<vector<int> >& prev = map[j-1];
					for(int k=0; k<prev.size(); ++k)
					{
						tmp = prev[k];
						tmp.push_back(j);
						poscache.push_back(tmp);
					}
				}
				else
				{
					tmp = vector<int>(1,0);
					poscache.push_back(tmp);
				}
			}
		}
		map[i] = poscache;
	}

	vector<vector<int> >& prev = map[s.size()-1];
	for(int i=0; i<prev.size(); ++i)
	{
		vector<string> res;

		for(int j=0; j<prev[i].size(); ++j)
			if(j==prev[i].size()-1)
				res.push_back(string(s,prev[i][j],s.size()-prev[i][j]));
			else
				res.push_back(string(s,prev[i][j],prev[i][j+1]-prev[i][j]));
		result.push_back(res);
	}
	return result;
}

/*void process(string s, int start, int end, vector<vector<string> >& result, vector<string>& res)
{
	if(start>end)
	{
		result.push_back(res);
		return;
	}

	for(int i=start; i<=end; ++i)
	{
		string tmp(s,start,i-start+1);
		if(func(s,start,i))
		{
			res.push_back(tmp);
			process(s,i+1,end,result,res);
			res.pop_back();
		}
	}
}

vector<vector<string> > partition(string s)
{
	vector<vector<string> > result;
	vector<string> res;
	process(s,0,s.size()-1,result,res);
	return result;
}*/

int main()
{
	vector<vector<string> > result = partition("aaa");
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
