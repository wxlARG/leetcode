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

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	vector<int> cache(gas.size(),0);
	for(int i=0; i<gas.size(); ++i)
		cache[i] = gas[i]-cost[i];

	int start=0,end=0;
	int sum=0;
	for(int i=0; i<cache.size(); ++i)
	{
		sum += cache[i];
		if(sum<0)
		{
			start = i+1;
			end = i+1;
			sum=0;
		}
		else
			end=i;
	}

	if(start==0 && end==cache.size()-1)
		return start;

	if(end!=cache.size()-1)
		return -1;
	else
	{
		sum=0;
		int pos = start;
		for(int i=0; i<cache.size(); ++i)
		{
			sum += cache[pos++%cache.size()];
			if(sum<0)
				return -1;
		}
		return start;
	}
}

int main()
{
	int gas_arr[]={6,1,4,3,5};
	int cost_arr[]={3,8,2,4,2};

	vector<int> gas;
	vector<int> cost;

	for(int i=0; i<sizeof(gas_arr)/sizeof(gas_arr[0]); ++i)
	{
		gas.push_back(gas_arr[i]);
		cost.push_back(cost_arr[i]);
	}

	int result = canCompleteCircuit(gas,cost);
	cout << result << endl;

	return 0;
}
