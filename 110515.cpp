#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<string.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	char count[255] = {0};
	string::iterator start = s.begin();
	string::iterator end = s.begin();
	int maxlen = 0;
	for(string::iterator iter=s.begin(); iter!=s.end(); ++iter)
	{
		if(count[*iter] != 0)
		{
			int num = end-start;
			maxlen = maxlen > num ? maxlen : num;

			while(*start != *iter)
			{
				--count[*start];
				++start;
			}
			--count[*start];
			++start;
		}
		++count[*iter];
		++end;
	}

	int num = end-start;
	maxlen = maxlen > num ? maxlen : num;

	return maxlen;
}

int main()
{
	string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	int len = lengthOfLongestSubstring(str);
	cout << len <<endl;
	return 0;
}


