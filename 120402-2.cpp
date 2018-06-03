#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

bool isNumber(const char *s)
{
	const char* p=s;

	while(*p == ' ')
		++p;

	char stat = 0;
	bool Pflag = 0;
	bool Eflag = 0;

	if(*p == '-' || *p=='+')
		++p;

	while(*p != 0)
	{
		if(*p>='0' && *p<='9')
		{
			if(stat == 'B')
				return false;
			stat = 'N';
		}
		else if(*p == '.')
		{
			if(Pflag == 0 && Eflag == 0)
				Pflag = 1;
			else
				return false;

			if(stat=='N')
				stat='P';
			else if(stat==0)
				stat='p';
			else
				return false;
		}
		else if(*p == 'e' || *p=='E')
		{
			if(Eflag == 0)
				Eflag = 1;
			else 
				return false;

			if(stat=='N' || stat == 'P')
			{
				stat = 'E';
				if(*(p+1) == '+' || *(p+1) == '-')
					++p;
			}
			else
				return false;
		}
		else if(*p == ' ')
		{
			if(stat == 'N' || stat == 'B' || stat == 'P')
				stat = 'B';
			else
				return false;
		}
		else
			return false;
		++p;
	}

	if(stat == 'N' || stat == 'B' || stat == 'P')
		return true;
	else
		return false;
}

int main()
{
	char s[] = " 005047e+6";
	bool result = isNumber(s);
	cout << result << endl;
	return 0;
}
