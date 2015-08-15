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

string minWindow(string S, string T)
{
	vector<int> result(2,-1);
	map<char, vector<int> > rmap;
	for(int i=0; i<T.size(); ++i)
	{
		map<char, vector<int> >::iterator it = rmap.find(T[i]);
		if(it == rmap.end())
		{
			vector<int> tmp(2,0);
			tmp[0] = 1;
			rmap.insert(pair<char, vector<int> >(T[i],tmp));
		}
		else
			++it->second[0];
	}

	int maxlen = INT_MAX;
	int start = 0;
	int zeronum = rmap.size();
	
	for(int end=start; end<S.size();++end)
	{
		map<char, vector<int> >::iterator it = rmap.find(S[end]);
		if(it != rmap.end())
		{
			if(it->second[1] == it->second[0]-1)
				--zeronum;
			++it->second[1];

			if(zeronum == 0)
			{
				while(1)
				{
					map<char, vector<int> >::iterator startptr = rmap.find(S[start]);
					if(startptr==rmap.end() || startptr->second[0] < startptr->second[1])
					{
						++start;
						if(startptr != rmap.end())
							--startptr->second[1];
					}
					else
						break;
				}

				if(maxlen > end-start+1)
				{
					maxlen = end-start+1;
					result[0] = start;
					result[1] = end;
				}
			}
		}
	}

	cout << result[0] << endl;
	cout << maxlen << endl;
	if(result[0] == -1)
		return string();
	else
		return string(S,result[0],maxlen);
}

int main()
{
//	string S = "ADOBECODEBANC";
//	string T = "ABC";

	string S = "aa";
	string T = "aa";

	string result = minWindow(S,T);
	cout << result << endl;
	return 0;
}
