#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<string.h>
using namespace std;
/*
string longestPalindrome(string s)
{
	int size = s.size();
	int finallen = 1;
	int start = 0;
	int end = 0;

	for(int i=0; i<size-1; ++i)
	{
		if(s[i] == s[i+1])
		{
			int len = 2;
			int j= i+1;
			int k=1;
			while(1)
			{
				if(i-k < 0 || j+k >= size)
				{
					if(len > finallen)
					{
						finallen = len;
						start = i-k+1;
						end = j+k-1;
					}
					break;
				}

				if(s[i-k] != s[j+k])
				{
					if(len > finallen)
					{
						finallen = len;
						start = i-k+1;
						end = j+k-1;
					}
					break;
				}
					
				len += 2;
				++k;
			}
		}

		int len = 1;
		int k = 1;
		while(1)
		{
			if(i-k < 0 || i+k >= size)
			{
				if(len > finallen)
				{
					finallen = len;
					start = i-k+1;
					end = i+k-1;
				}
				break;
			}

			if(s[i-k] != s[i+k])
			{
				if(len > finallen)
				{
					finallen = len;
					start = i-k+1;
					end = i+k-1;
				}
				break;
			}

			len += 2;
			++k;
		}
	}

	string result(s,start,finallen);
	return result;
}
	*/
string longestPalindrome(string s)
{
	string cache(2*s.size()+1,'#');
	for(int i=1; i<cache.size(); i+=2)
		cache[i] = s[i/2];

	int pos=0,mr=0;
	vector<int> radius(cache.size(),1);
	for(int i=1; i<cache.size(); ++i)
	{
		if(mr>i)
			radius[i] = min(mr-i, radius[max(0,2*pos-i)]);

		while(i-radius[i]>=0 && i+radius[i]<cache.size() && cache[i+radius[i]] == cache[i-radius[i]])
			++radius[i];

		if(i+radius[i] > mr)
		{
			pos = i;
			mr = i+radius[i];
		}
	}

	int start=0, maxval=0;
	for(int i=0; i<radius.size(); ++i)
	{
		if(radius[i]>maxval)
		{
			maxval = radius[i];
			start = (i-radius[i]+1)/2;
		}
	}

	return string(s,start,maxval-1);
}

int main()
{
	string s = "abba";
	string result = longestPalindrome(s);
	cout <<result<<endl;
	return 0;
}


