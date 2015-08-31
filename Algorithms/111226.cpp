#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<climits>
using namespace std;

int atoi(const char *str)
{
	int num = 0;
	int flag = 1;

	const char* p = str;

	while(*p==' ' || *p=='\t' || *p=='\n')
		++p;

	if(*p == '+')
	{
		flag = 1;
		++p;

		if(!(*p>='0' && *p<='9'))
			return num;
	}

	if(*p == '-')
	{
		flag = -1;
		++p;

		if(!(*p>='0' && *p<='9'))
			return num;
	}

	if(!(*p>='0' && *p<='9'))
		return num;

	int overflowFlag = 0;
	for(; *p!=0 ; ++p)
	{
		if(!(*p>='0' && *p<='9'))
			break;

		if(num > INT_MAX/10)
			if(flag == 1)
				return INT_MAX;
			else if(flag == -1)
				return INT_MIN;

		if(num == INT_MAX/10)
		{
			if(flag == 1 && (*p-'0')>=INT_MAX%10)
				return INT_MAX;
			
			if(flag == -1 && (*p-'0')>=(INT_MAX%10+1))
				return INT_MIN;
		}

		num = num*10 + (*p-'0');
	}

	return num*flag;
}

int main()
{
	char str[] = "      -11919730356x";
	const char* p = str;

	int result = atoi(p);
	cout<<result<<endl;
	return 0;
}


