#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

void func(vector<string>& result, vector<string>& cache, string& s, int end, int count)
{
	if(end < 0)
		return;

	string num;

	if(count == 0)
	{
		num = string(s,0,end+1);
		if(num.size()>3 || (num.size()==3 && num>"255") || (num.size()>1 && num[0]=='0'))
			return;

		for(int i=cache.size()-1; i>=0; --i)
			num += "." + cache[i];
		result.push_back(num);
		return;
	}

	int start = max(0,end-2);
	for(int i=start; i<=end; ++i)
	{
		num = string(s,i,end-i+1);
		if(num.size()>3 || (num.size()==3 && num>"255") || (num.size()>1 && num[0]=='0'))
			continue;

		cache.push_back(num);
		func(result,cache,s,i-1,count-1);
		cache.pop_back();
	}
}

vector<string> restoreIpAddresses(string s)
{
	vector<string> result;
	vector<string> cache;
	func(result,cache,s,s.size()-1,3);
	return result;
}

int main()
{
//	string s("25525511135");
	string s("010010");
	vector<string> result = restoreIpAddresses(s);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
