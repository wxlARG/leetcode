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

bool isMatch(const char *s, const char *p)
{
	int len1 = strlen(s);
	int len2 = strlen(p);

	bool** arr = new bool*[len2+1];
	for(int i=0; i<len2+1; ++i)
	{
		arr[i] = new bool[len1+1];
		for(int j=0; j<len1+1; ++j)
			arr[i][j] = 0;
	}

	arr[0][0] = 1;

	for(int i=1; i<len2+1; ++i)
	{
		int flag = 0;
		if(p[i] == '*')
		{
			arr[i][0] = arr[i-1][0];
			flag = 1;
		}

		for(int j=1; j<len1+1; ++j)
		{
			if(p[i] == '*')
			{
				if(s[j-1] != p[i-1] && p[i-1] != '.')
					arr[i][j] = arr[i-1][j];
				else
					arr[i][j] = max(arr[i][j-1],arr[i-1][j]);

				flag = 1;
			}
			else
			{
				if(p[i-1] == s[j-1] || p[i-1] == '.')
					arr[i][j] = arr[i-1][j-1];
			}
		}

		if(flag == 1)
		{
			++i;
			for(int j=0; j<len1+1; ++j)
				arr[i][j] = arr[i-1][j];
		}
	}

	for(int i=0; i<len2+1; ++i)
	{
		for(int j=0; j<len1+1; ++j)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	return arr[len2][len1];
}

int main()
{
//	const char *s = "aaa";
//	const char*p = "ab*a*c*a";
//	const char *s = "ab";
//	const char*p = ".*";
	const char *s = "aab";
	const char*p = "c*a*b";
//	const char *s = "";
//	const char*p = ".*";
	bool result = isMatch(s,p);
	cout<<result<<endl;
	return 0;
}


