#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

void func(int x, int start, int end, int& target, int& dis)
{
	if(dis == 0 || start>end)
		return;

	int mid = start+(end-start)/2;
	int result = x/mid;

/*	if(abs(result*result-x) < dis)
	{
		target = result;
		dis = abs(result*result-x);
	}

	if(abs(mid*mid-x) < dis)
	{
		target = mid;
		dis = abs(mid*mid-x);
	}*/

	if(abs(result-mid) < dis)
	{
		target = min(result,mid);
		dis = abs(result-mid);
	}

	if(mid>result)
		func(x,start,mid-1,target,dis);
	else
		func(x,mid+1,end,target,dis);

}

int sqrt(int x)
{
	int target = 0;
	int dis = INT_MAX;

	func(x,1,x,target,dis);
	return target;
}

int main()
{
	int result = sqrt(3);
	cout << result << endl;
	return 0;
}
