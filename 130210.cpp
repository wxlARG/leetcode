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

int ladderLength(string start, string end, unordered_set<string> &dict)
{
	int result=0;
	deque<string> queue;
	unordered_map<string,string> parents;
	bool breakflag = 0;
	queue.push_back(start);

	while(!queue.empty())
	{
		string curstr = queue.front();
		string origin = curstr;
		queue.pop_front();

		for(int i=0; i<curstr.size(); ++i)
		{
			char cachechar = curstr[i];
			for(int j='a'; j<='z'; ++j)
			{
				curstr[i]=j;
				if(curstr == origin)
					continue;

				if((curstr == end || dict.find(curstr)!=dict.end()) && parents.find(curstr)==parents.end())
				{
					queue.push_back(curstr);
					parents.insert(make_pair(curstr,origin));
					if(curstr==end) breakflag=1;
					if(breakflag) break;
				}
			}
			curstr[i]=cachechar;
			if(breakflag) break;
		}
		if(breakflag) break;
	}

	if(!breakflag)
		return 0;

	string tmpstr = end;
	while(tmpstr!=start)
	{
		tmpstr = parents.find(tmpstr)->second;
		++result;
	}

	return result+1;
}

int main()
{
	string start("hit");
	string end("cog");

	string arr[] = {"hot","dot","dog","lot","log"};
	unordered_set<string> dict;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		dict.insert(arr[i]);

	int result = ladderLength(start,end,dict);
	cout << result << endl;
	return 0;
}
