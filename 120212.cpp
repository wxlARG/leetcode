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

void func(deque<char>& stack, int left, int right, vector<string>& result)
{
	if(left == 0 && right == 0)
	{
		result.push_back(string(stack.begin(),stack.end()));
		return;
	}

	if(left > right)
		return;
	
	if(left > 0)
	{
		stack.push_back('(');
		func(stack,left-1,right,result);
		stack.pop_back();
	}

	if(right > 0)
	{
		stack.push_back(')');
		func(stack,left,right-1,result);
		stack.pop_back();
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> result;
	deque<char> stack;
	func(stack,n,n,result);
	return result;
}

int main()
{
	vector<string> result = generateParenthesis(3);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
