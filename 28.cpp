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

int strStr(string haystack, string needle)
{
	int needlelen = needle.size();
	int haystacklen = haystack.size();
	if(needlelen == 0)
		return 0;

	vector<int> next(needle.size(),-1);
	int k=-1;
	int j=0;
	while(j<needlelen-1)
	{
		if(k==-1 || needle[k] == needle[j])
		{
			++k;
			++j;
			next[j]=k;
/*
			if(needle[k] == needle[j])
				next[j] = next[k];
			else
				next[j]=k;
*/
		}
		else
			k=next[k];
	}

	int i=0;
	j=0;
	while(i<haystacklen)
	{
		if(j==-1 || haystack[i]==needle[j])
		{
			++i;
			++j;
		}
		else
			j=next[j];

		if(j==needlelen)
			return i-j;

/*
		if(j==needlelen)
		{
			cout << i-j << endl;
			--i;
			--j;
			j=next[j];
		}
*/
	}

	return -1;
}

int main()
{
	int result = strStr("", "");
	cout << result << endl;

	return 0;
}
