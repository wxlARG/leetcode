#include<iostream>
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

int numDecodings(string s)
{
	if(s.size()==0 || s[0]=='0')
		return 0;

	int last=1,cur=1;
	for(int i=1; i<s.size(); ++i)
	{
		int tmpcur;
		if(s[i]=='0')
		{
			if(s[i-1] == '0' || s[i-1] > '2')
				return 0;
			else
				tmpcur = last;
		}
		else if(s[i-1]!='0' && (s[i-1]-'0')*10+s[i]-'0'<=26)
			tmpcur = cur+last;
		else
			tmpcur = cur;

		last = cur;
		cur = tmpcur;
	}

	return cur;
}

int main()
{
	string s = "130";
	int result = numDecodings(s);
	cout << result << endl;
	return 0;
}
