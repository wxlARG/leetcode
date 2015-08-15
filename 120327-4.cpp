#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

string getPermutation(int n, int k)
{
	string result;
	map<int, int> res;
	vector<int> arr(n);
	int num = 1;
	for(int i=1; i<n; ++i)
	{
		arr[i-1]=i;
		num *= i;
		res.insert(pair<int,int>(i,num));
	}
	arr[n-1] = n;

	--k;
	for(int i=n-1; i>0; --i)
	{
		int pos = k/res[i];
		result += arr[pos]+'0';
		for(int j=pos+1;j<=i;++j)
			swap(arr[j-1],arr[j]);

		k%=res[i];
	}

	result += arr[0]+'0';
	return result;
}

int main()
{
	string result = getPermutation(4,4);
	cout << result << endl;
	return 0;
}
