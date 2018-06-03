#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

string simplifyPath(string path)
{
	string result("/");
	deque<string> stack;
	int pos = 0;

	while(path[pos]=='/')
		++pos;

	while(pos<path.size())
	{
		int start = pos;
		while(pos<path.size() && path[pos]!='/')
			++pos;
		string tmp(path,start,pos-start);
		if(tmp == "..")
		{
			if(stack.size()>0)
				stack.pop_back();
		}
		else if(tmp != ".")
			stack.push_back(tmp);

		while(path[pos] == '/')
			++pos;
	}

	while(stack.size()!=0)
	{
		result += stack.front()+"/";
		stack.pop_front();
	}
	if(result.size() > 1)
		result.erase(result.size()-1,1);
	return result;
}

int main()
{
	string path = "/../";
	string result = simplifyPath(path);
	cout << result << endl;
	return 0;
}
