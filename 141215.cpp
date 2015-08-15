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

int compareVersion(string version1, string version2)
{
	const char* p1 = version1.c_str();
	const char* p2 = version2.c_str();

	while(*p1!=0 || *p2!=0)
	{
		int num1=0, num2=0;
		while(*p1!=0 && *p1!='.')
		{
			num1 = num1*10+*p1-'0';
			++p1;
		}

		while(*p2!=0 && *p2!='.')
		{
			num2 = num2*10+*p2-'0';
			++p2;
		}

		if(num1<num2) return -1;
		if(num1>num2) return 1;

		if(*p1!=0) ++p1;
		if(*p2!=0) ++p2;
	}
	return 0;
}

int main()
{
	int result = compareVersion("1.1","1.01.0");
	cout << result << endl;
	return 0;
}
