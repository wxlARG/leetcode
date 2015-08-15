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

int divide_P(int dividend, int divisor, int& remain)
{
	int flag = 0;
	if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
		flag = 1;

	if(flag)
	{
		if((dividend>=0 && dividend+divisor<0) || (dividend<=0 && dividend+divisor>0))
		{
			remain = dividend;
			return 0;
		}
	}
	else
	{
		if((dividend<=0 && dividend-divisor>0) || (dividend>=0 && dividend-divisor<0))
		{
			remain = dividend;
			return 0;
		}
	}

	if(dividend & 1 != 0)
	{
		if(dividend>0)
		{
			++remain;
			--dividend;
		}
		else if(dividend<0)
		{
			--remain;
			++dividend;
		}
	}

	int tmp = 0;
	int result = divide_P(dividend>>1, divisor, tmp);
	result += result;
	tmp += tmp;
	remain += tmp;

	if(flag)
	{
		while((remain>0 && remain+divisor>=0) || (remain<0 && remain+divisor<=0))
		{
			--result;
			remain += divisor;
		}
	}
	else
	{
		while((remain<0 && remain-divisor<=0) || (remain>0 && remain-divisor>=0))
		{
			++result;
			remain -= divisor;
		}
	}

	return result;
}

int divide(int dividend, int divisor)
{
	int remain = 0;
	int result = divide_P(dividend, divisor, remain);

	return result;
}

int main()
{
//	int result = divide(-1010369383,-2147483648);
	int result = divide(-2147483648,-2147483648);
	cout << result << endl;
	return 0;
}
