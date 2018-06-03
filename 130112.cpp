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

bool isPalindrome(string s)
{
	int pos=0,end=0;
	while(end<s.size())
	{
		if(isalnum(s[end]))
			s[pos++]=tolower(s[end]);
		++end;
	}

	int after=pos/2+1,before=pos/2-1;
	if(pos%2==0)
		after = pos/2;

	while(before>=0 && after<pos)
		if(s[before--] != s[after++])
			return false;
	return true;
}

int main()
{
	string s("1a2");
	bool result = isPalindrome(s);
	cout << result << endl;
	return 0;
}
