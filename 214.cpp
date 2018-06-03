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

string shortestPalindrome(string s)
{
	string result;
	string cache(2*s.size()+1,'#');
	for(int i=1; i<cache.size(); i+=2)
		cache[i] = s[i/2];

	int pos=0,mr=0,maxlen=1;
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

		if((i-radius[i]+1)/2 == 0 && radius[i]>maxlen)
			maxlen = radius[i];
	}

	for(int i=s.size()-1; i>maxlen-2; --i)
		result += s[i];

	result += s;
	return result;
}

int main()
{
	string result = shortestPalindrome("abcd");
	cout << result << endl;
	return 0;
}
