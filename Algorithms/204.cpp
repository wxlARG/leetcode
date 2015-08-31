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

bool getcache(vector<int>& cache, int i)
{
	int pos1 = i/32;
	int pos2 = i%32;

	int tmp = cache[pos1];
	return tmp & (1<<pos2);
}

void setcache(vector<int>& cache, int i)
{
	int pos1 = i/32;
	int pos2 = i%32;

	int &tmp = cache[pos1];
	tmp |= (1<<pos2);
}

int countPrimes(int n)
{
	int result = 0;
	vector<int> cache(ceil(n/32.0),0);
	for(int i=2; i<n; ++i)
	{
		if(!getcache(cache,i))
		{
			++result;
			for(int j=2; i*j<n; ++j)
				setcache(cache, i*j);
		}
	}

	return result;
}

int main()
{
	int result = countPrimes(19);
	cout << result << endl;
	return 0;
}
