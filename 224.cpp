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

int calculate(string s)
{
	deque<int> stack;
	int tmp = 0;

	for(int i=0; i<s.size(); ++i)
	{
		if(s[i]==' ') continue;

		if(s[i]=='+' || s[i]=='-' || s[i]=='(')
			stack.push_back(s[i]);
		else if(s[i]>='0' && s[i]<='9')
		{
			tmp = tmp*10 + s[i]-'0';
			if(i+1 != s.size() && s[i+1]>='0' && s[i+1]<='9')
				continue;

			if(stack.empty() || stack.back()=='(')
				stack.push_back(tmp);
			else if(stack.back()=='+')
			{
				stack.pop_back();
				stack.back() += tmp;
			}
			else if(stack.back()=='-')
			{
				stack.pop_back();
				stack.back() -= tmp;
			}

			tmp=0;
		}
		else
		{
			int tmp = stack.back();
			stack.pop_back();
			stack.pop_back();

			if(stack.empty() || stack.back()=='(')
				stack.push_back(tmp);
			else if(stack.back()=='+')
			{
				stack.pop_back();
				stack.back() += tmp;
			}
			else if(stack.back()=='-')
			{
				stack.pop_back();
				stack.back() -= tmp;
			}
		}
	}
	return stack.back();
}

int main()
{
	int result = calculate("1-11");
	cout << result << endl;
	return 0;
}
