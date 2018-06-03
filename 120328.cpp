#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int uniquePaths(int m, int n)
{
	vector<int> cache(n,1);

	for(int i=1; i<m; ++i)
		for(int j=1; j<n; ++j)
			cache[j] += cache[j-1];
	return cache[n-1];
}

int main()
{
	int result = uniquePaths(3,3);
	cout << result << endl;
	return 0;
}
