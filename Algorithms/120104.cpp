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

bool isPalindrome(int x) 
{
	if(x < 0)
		return false;

	if(x/10 == 0)
		return true;

	int z = x;
	int y = 0;
	while(1)
	{
		z /= 100;
		y = y*10+x%10;
		x /= 10;

		if(z == 0)
			break;
		else if(z/10 == 0)
		{
			x/=10;
			break;
		}
	}

	return x==y;
}

int main()
{
	int x=12211;
	bool result = isPalindrome(x);
	cout<<result<<endl;
	return 0;
}


