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

bool isValid(string s)
{
	deque<char> deque;
	for(int i=0; i<s.size(); ++i)
	{
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
			deque.push_back(s[i]);
		else
		{
			if(s[i]==')')
				if(!deque.empty() && deque.back()=='(')
					deque.pop_back();
				else
					return false;
			else if(s[i]==']')
				if(!deque.empty() && deque.back()=='[')
					deque.pop_back();
				else
					return false;
			else if(s[i]=='}')
				if(!deque.empty() && deque.back()=='{')
					deque.pop_back();
				else
					return false;
		}
	}
	if(deque.empty())
		return true;
	else
		return false;
}

int main()
{
	string s = "(]";
	bool result = isValid(s);
	cout << result << endl;
	return 0;
}
