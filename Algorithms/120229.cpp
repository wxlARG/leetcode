#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int longestValidParentheses(string s)
{
	int result = 0;
	int num = 0;
	deque<vector<int> > stack;
	vector<int> len(s.size(),0);

	for(int i=0; i<s.size(); ++i)
	{
		if(s[i] == ')')
		{
			if(stack.size() != 0 && stack.back()[0] == '(')
			{
				vector<int> tmp = stack.back();
				stack.pop_back();
				len[tmp[1]] = i-tmp[1]+1;
			}
		}
		else
		{
			vector<int> tmp(2);
			tmp[0] = s[i];
			tmp[1] = i;
			stack.push_back(tmp);
		}
	}

	for(int i=0; i<len.size();)
	{
		if(len[i] != 0)
		{
			num += len[i];
			i+=len[i];
		}
		else
		{
			if(result < num)
				result = num;
			num=0;
			++i;
		}
	}

	if(result < num)
		result = num;

	return result;
}

int main()
{
//	string s = ")()())";
	string s = "())())(";
	int result = longestValidParentheses(s);
	cout << result << endl;
	return 0;
}
