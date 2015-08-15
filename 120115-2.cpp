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

int romanToInt(string s)
{
	int result = 0;
	int size = s.size();
	int pos = 0;

	int map[26] = {0};
	map['I'-'A'] = 1;
	map['V'-'A'] = 5;
	map['X'-'A'] = 10;
	map['L'-'A'] = 50;
	map['C'-'A'] = 100;
	map['D'-'A'] = 500;
	map['M'-'A'] = 1000;

	while(1)
	{
		int cur = map[s[pos]-'A'];
		int next = INT_MAX;
		if(pos+1 < size)
			next = map[s[pos+1]-'A'];

		if(pos+1 < size && cur < next)
		{
			result += next-cur;
			pos += 2;
		}
		else
		{
			result += cur;
			++pos;
		}

		if(pos >= size)
			break;

	}

	return result;
}

int main()
{
	string s("MDCCCLXXX");
	int result = romanToInt(s);
	cout<<result<<endl;
	return 0;
}


