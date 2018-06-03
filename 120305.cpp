#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

string func(string str)
{
	int num = 0;
	string tmp;
	for(int i=0; i<str.size(); ++i)
	{
		if(i==0 || str[i] == str[i-1])
			++num;
		else
		{
			string numstr;
			stringstream  stream;
			stream<<num;
			stream >> numstr;

			tmp += numstr;
			tmp += str[i-1];
			num = 1;
		}
	}

	if(num != 0)
	{
		string numstr;
		stringstream  stream;
		stream<<num;
		stream >> numstr;

		tmp += numstr;
		tmp += str[str.size()-1];
	}

	return tmp;
}

string countAndSay(int n)
{
	string str(1,'1');

	for(int i=1; i<n; ++i)
		str = func(str);

	return str;
}

int main()
{
	string result = countAndSay(4);
	cout << result << endl;
	return 0;
}
