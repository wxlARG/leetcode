#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

string addBinary(string a, string b)
{
	string result;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int flag = 0;
	int asize = a.size();
	int bsize = b.size();
	int apos = 0;
	int bpos = 0;

	while(apos<asize && bpos<bsize)
	{
		int tmp = a[apos++]-'0'+b[bpos++]-'0'+flag;
		flag = tmp/2;
		tmp%=2;
		result += tmp+'0';
	}

	while(apos<asize)
	{
		int tmp = a[apos++]-'0'+flag;
		flag = tmp/2;
		tmp%=2;
		result += tmp+'0';
	}

	while(bpos<bsize)
	{
		int tmp = b[bpos++]-'0'+flag;
		flag = tmp/2;
		tmp%=2;
		result += tmp+'0';
	}

	if(flag != 0)
		result += flag+'0';

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string a = "11";
	string b = "1";
	string result = addBinary(a,b);
	cout << result << endl;
	return 0;
}
