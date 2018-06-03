#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

int reverse(int x)
{
	int flag = 1;
	if(x < 0)
		flag = -1;

	x*=flag;
	int result = 0;

	while(x != 0)
	{
		int num = x % 10;
		result = result * 10 + num;
		x /= 10;
	}

	return result*flag;
}

int main()
{
	int x = -123;
	int result = reverse(x);
	cout<<result<<endl;
	return 0;
}


