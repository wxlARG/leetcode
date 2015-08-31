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

void func(vector<int>& result, int n)
{
	if(n==1)
	{
		result.push_back(0);
		result.push_back(1);
		return;
	}

	func(result, n-1);
	int addnum = 1<<n-1;
	int size = result.size();
	for(int i=size-1; i>=0; --i)
		result.push_back(result[i]+addnum);
}

vector<int> grayCode(int n)
{
	vector<int> result;

	if(n==0)
	{
		result.push_back(0);
		return result;
	}

	func(result,n);
	return result;
}

int main()
{
	vector<int> result = grayCode(3);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
