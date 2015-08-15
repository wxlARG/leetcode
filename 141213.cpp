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

void csort(vector<int> &result, vector<int> &num, int pos)
{
	vector<int> count(256,0);
	int mask = 0xff<<(8*pos);
	for(int i=0; i<num.size(); ++i)
		++count[(num[i]&mask)>>(8*pos)];

	for(int i=1; i<256; ++i)
		count[i] += count[i-1];

	for(int i=num.size()-1; i>=0; --i)
		result[--count[(num[i]&mask)>>(8*pos)]] = num[i];

}

int maximumGap(vector<int> &num)
{
	vector<int> num2(num.size(),0);
	csort(num2,num,0);
	csort(num,num2,1);
	csort(num2,num,2);
	csort(num,num2,3);

	int result = 0;
	for(int i=1; i<num.size(); ++i)
		if(num[i]-num[i-1] > result)
			result = num[i]-num[i-1];

	return result;
}

int main()
{
	vector<int> num;
	int arr[] = {2,99999999};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	int result = maximumGap(num);
	cout << result << endl;
	return 0;
}
