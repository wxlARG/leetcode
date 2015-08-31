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

bool isPowerOfTwo(int n)
{
	if(n<=0)
		return 0;

	int zerocount = 0;
	while(n!=0)
	{
		if(n&1 != 0)
			++zerocount;
		n >>= 1;
	}
	return zerocount==1 ? 1 : 0;
}

int main()
{
	bool result = isPowerOfTwo(-16);
	cout << result << endl;
	return 0;
}
