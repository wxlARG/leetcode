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

vector<int> getRow(int rowIndex)
{
	vector<int> result(rowIndex+1,1);
	for(int i=0; i<=rowIndex; ++i)
		for(int j=i-1; j>=1; --j)
			result[j] += result[j-1];
	return result;
}

int main()
{
	vector<int> result = getRow(5);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
