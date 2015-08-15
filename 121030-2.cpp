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

	int start = 0;
	int end = 0;
	int max = 0;

	for(int cur=1; cur<prices.size(); ++cur)
	{
		if(prices[cur] > prices[cur-1])
			++end;
		else
		{
			max += prices[end] - prices[start];
			end = cur;
			start = cur;
		}
	}

	max += prices[end] - prices[start];
	return max;
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
