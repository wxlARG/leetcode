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

int evalRPN(vector<string> &tokens)
{
	int result = 0;
	deque<int> stack;

	for(int i=0; i<tokens.size(); ++i)
	{
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			int num1 = stack.back();
			stack.pop_back();
			int num2 = stack.back();
			stack.pop_back();
			int target = 0;

			if(tokens[i] == "+")
				target = num2 + num1;
			else if(tokens[i] == "-")
				target = num2 - num1;
			else if(tokens[i] == "*")
				target = num2 * num1;
			else
				target = num2 / num1;

			stack.push_back(target);
		}
		else
		{
			stringstream s;
			s << tokens[i];
			int num;
			s >> num;
			stack.push_back(num);
		}
	}

	result = stack[0];

	return result;
}

int main()
{
//	string arr[] = {"2", "1", "+", "3", "*"};
	string arr[] = {"18"};
	vector<string> tokens;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		tokens.push_back(arr[i]);

	int result = evalRPN(tokens);

	cout << result << endl;
	return 0;
}
