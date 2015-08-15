#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;

int longestConsecutive(vector<int> &num)
{
	int result = 1;
	unordered_map<int,int> map;
	for(int i=0; i<num.size(); ++i)
		if(map.find(num[i])==map.end())
			map[num[i]]=1;

	for(unordered_map<int,int>::iterator iter=map.begin(); iter!=map.end();)
	{
		int max=1;
		int pos = iter->first;

		unordered_map<int,int>::iterator it;
		while((it=map.find(--pos))!=map.end())
		{
			++max;
			map.erase(it);
		}

		pos = iter->first;
		while((it=map.find(++pos))!=map.end())
		{
			++max;
			map.erase(it);
		}

		if(result<max)
			result = max;

		map.erase(iter++);
	}
	return result;
}

int main()
{
	vector<int> num;
	int arr[] = {100, 4, 200, 1, 3, 2};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	int result = longestConsecutive(num);
	cout << result << endl;
	return 0;
}
