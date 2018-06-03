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

int maxProfit(vector<int> &prices)
{
	if(prices.size() == 0)
		return 0;

	deque<int> r1;
	deque<int> r2;

	int min = prices[0];
	int max = prices[prices.size()-1];
	int maxArr = 0;
	int result = 0;

	for(int i=0; i<prices.size(); ++i)
	{
		if(min > prices[i])
			min = prices[i];

		int tmp = prices[i] - min;

		if(maxArr < tmp)
			maxArr = tmp;
		r1.push_back(maxArr);
	}

	maxArr = 0;

	for(int i=prices.size()-1; i>=0; --i)
	{
		if(max < prices[i])
			max = prices[i];

		int tmp = max-prices[i];

		if(maxArr < tmp)
			maxArr = tmp;

		r2.push_front(maxArr);
	}

	for(int i=0; i<prices.size()-1; ++i)
	{
		int tmp = r1[i]+r2[i+1];
		if(result < tmp)
			result = tmp;
	}

	if(result < r1[prices.size()-1])
		result = r1[prices.size()-1];
	
	if(result < r2[0])
		result = r2[0];

	return result;
}

int main()
{
	int arr[] = {2,1,4,5,2,9,7};
	vector<int> prices;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		prices.push_back(arr[i]);

	int result = maxProfit(prices);
	cout << result << endl;
	return 0;
}
