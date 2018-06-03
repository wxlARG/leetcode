#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
	reverse(digits.begin(),digits.end());
	int flag = 0;
	vector<int> result;

	for(int i=0; i<digits.size(); ++i)
	{
		int tmp;
		if(i==0)
			tmp = digits[i] + 1 + flag;
		else
			tmp = digits[i] + flag;

		result.push_back(tmp%10);
		flag = tmp/10;
	}

	if(flag != 0)
		result.push_back(flag);

	reverse(result.begin(),result.end());
	return result;
}

int main()
{
	vector<int> digits;
	int arr[] = {9,9,9,9};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		digits.push_back(arr[i]);

	vector<int> result = plusOne(digits);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
