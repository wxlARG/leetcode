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
	deque<int> nums;
	deque<int> symbols;
	int tmp = 0;

	for(int i=0; i<s.size(); ++i)
	{
		if(s[i]==' ') continue;

		if(s[i]>='0' && s[i]<='9')
		{
			tmp = tmp*10 + s[i]-'0';
			if(i+1 != s.size() && s[i+1]>='0' && s[i+1]<='9')
				continue;

			nums.push_back(tmp);
			tmp = 0;
		}
		else
		{
			char cur = s[i];
			if(symbols.empty())
				symbols.push_back(cur);
			else if(cur=='+' || cur=='-')
			{
				while(!symbols.empty())
				{
					char last = symbols.back();
					symbols.pop_back();

					int right = nums.back();
					nums.pop_back();

					if(last == '*')
						nums.back() *= right;
					else if(last == '/')
						nums.back() /= right;
					else if(last == '+')
						nums.back() += right;
					else
						nums.back() -= right;
				}

				symbols.push_back(cur);
			}
			else if(cur=='*' || cur=='/')
			{
				char last = symbols.back();
				if(last=='*' || last=='/')
				{
					symbols.pop_back();

					int right = nums.back();
					nums.pop_back();

					if(last == '*')
						nums.back() *= right;
					else
						nums.back() /= right;
				}
				symbols.push_back(cur);
			}
		}
	}

	while(!symbols.empty())
	{
		char last = symbols.back();
		symbols.pop_back();

		int right = nums.back();
		nums.pop_back();

		if(last == '*')
			nums.back() *= right;
		else if(last == '/')
			nums.back() /= right;
		else if(last == '+')
			nums.back() += right;
		else
			nums.back() -= right;
	}

	return nums.back();
}

int main()
{
	int result = calculate(" 3+5 / 2 ");
	cout << result << endl;
	return 0;
}
