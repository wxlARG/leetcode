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

int numTrees(int n)
{
	int* f = new int[n+1];
	f[0] = 1;
	f[1] = 1;

	for(int i=2; i<=n; ++i)
	{
		f[i] = 0;
		int start = 0;
		int end = i-1;

		while(start < end)
		{
			f[i] += 2*f[start]*f[end];
			++start;
			--end;
		}

		if(start == end)
			f[i] += f[start]*f[end];
	}

	int result = f[n];
	delete f;
	return result;
}

int main()
{
	int result = numTrees(4);
	cout << result << endl;
	return 0;
}
