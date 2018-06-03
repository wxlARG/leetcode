#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

vector<string> anagrams(vector<string> &strs)
{
	vector<string> result;
	map<string, int> cache;

	for(int i=0; i<strs.size(); ++i)
	{
		string tmp = strs[i];
		sort(tmp.begin(), tmp.end());

		map<string, int>::iterator iter = cache.find(tmp);
		if(iter == cache.end())
			cache.insert(pair<string, int>(tmp,i));
		else
		{
			if(iter->second != -1)
			{
				result.push_back(strs[iter->second]);
				iter->second = -1;
			}

			result.push_back(strs[i]);
		}
	}

	return result;
}

int main()
{
	vector<string> strs;
	strs.push_back("tea");
	strs.push_back("eat");
	strs.push_back("aet");
	strs.push_back("asg");

	vector<string> result = anagrams(strs);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
