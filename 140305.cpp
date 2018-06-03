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

void reverseWords(string &s)
{
	reverse(s.begin(), s.end());
	string::iterator start = s.begin();
	string::iterator end = s.begin();

	while(end != s.end())
	{
		while(start != s.end() && *start == ' ')
			++start;

		end = start;

		while(end != s.end() && *end != ' ')
			++end;

		reverse(start, end);
		start = end;
	}

	string::iterator pos = s.begin();
	for(string::iterator iter = s.begin(); iter!=s.end(); ++iter)
	{
		if((*iter != ' ') || (pos != s.begin() && *(pos-1) != ' '))
		{
			*pos = *iter;
			++pos;
		}
	}

	while(*(pos-1) == ' ')
		--pos;

	s.erase(pos,s.end());
}

int main()
{
	string s = " 1";
	reverseWords(s);
	cout << s << "\t" << s.size() << endl;
	return 0;
}
