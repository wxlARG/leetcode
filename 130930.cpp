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

int candy(vector<int> &ratings)
{
	int sum=0;
	int end=0;

	while(end<ratings.size())
	{
		int start = end;
		while(end<ratings.size()-1 && ratings[end]<ratings[end+1])
			++end;

		int peekpos=end;
		int leftnum=1;
		while(start<peekpos)
		{
			sum+=leftnum;
			++leftnum;
			++start;
		}
		--leftnum;

		if(end==ratings.size()-1)
		{
			int peeknum=leftnum+1;
			sum += peeknum;
			++end;
			continue;
		}

		++end;
		while(end<ratings.size()-1 && ratings[end]>ratings[end+1])
			++end;

		int rightnum=2;
		int tmpend=end-1;
		while(tmpend>peekpos)
		{
			sum+=rightnum;
			++rightnum;
			--tmpend;
		}
		--rightnum;

		int tmp=leftnum+1;
		if(peekpos<ratings.size()-1 && ratings[peekpos]!=ratings[peekpos+1])
			tmp = max(tmp,rightnum+1);
		sum+=tmp;
	}
	return sum;
}

int main()
{
	//int arr[]={58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
	int arr[] = {1,2,3,4,5};
	vector<int> ratings;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
	{
		ratings.push_back(arr[i]);
	}

	int result = candy(ratings);
	cout << result << endl;

	return 0;
}
