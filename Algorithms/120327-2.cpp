#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int lengthOfLastWord(const char *s)
{
	int n = strlen(s);

	int start = 0;
	int end = 0;
	int result = 0;

	while(end < n)
	{
		while(end<n && s[end]==' ')
			++end;
		start = end;

		int tmplen = 0;

		while(end<n && s[end]!=' ')
			++end;

		if(end-start != 0)
			result = end-start;

		start = end;
	}

	return result;
}

int main()
{
	char s[] = "Hello World  ";
	int result = lengthOfLastWord(s);
	cout << result << endl;
	return 0;
}
