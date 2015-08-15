#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_set>
using namespace std;

int func(int n)
{
	vector<int> cache;
	int result = 0;

	while(n)
	{
		int tmp = n%10;
		n /= 10;
		result += tmp*tmp;
	}

	while(result)
	{
		int tmp = result%10;
		result /= 10;
		cache.push_back(tmp);
	}

	sort(cache.begin(),cache.end());
	result = 0;
	for(int i=0; i<cache.size(); ++i)
		result = result*10 + cache[i];
	return result;
}

bool isHappy(int n)
{
	unordered_set<int> cache;
	while(1)
	{
		if(n == 1)
			return 1;
		else if(cache.find(n) != cache.end())
			return 0;
		else
		{
			cache.insert(n);
			n = func(n);
		}
	}
}

int main()
{
	bool result = isHappy(19);
	cout << result << endl;
	return 0;
}
