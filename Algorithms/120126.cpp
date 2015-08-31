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

vector<vector<int> > fourSum(vector<int> &num, int target)
{
	vector<vector<int> > result;
	stable_sort(num.begin(),num.end());
	int endPos = num.size()-1;
	int startout = 0;
	int endout = endPos;

	while(startout < endout)
	{
		if(startout > 0 && num[startout] == num[startout-1])
		{
			++startout;
			continue;
		}

		if(endout < endPos && num[endout] == num[endout+1])
		{
			--endout;
			continue;
		}

		if(startout+2 < endout && num[startout] + num[startout+1] + num[startout+2] + num[endout] > target)
		{
			--endout;
			continue;
		}

		if(startout < endout-2 && num[startout] + num[endout-2] + num[endout-1] + num[endout] < target)
		{
			++startout;
			continue;
		}

		int endoutTmp = endout;
		while(startout < endoutTmp)
		{
			int startin = startout+1;
			int endin = endoutTmp-1;

			while(startin < endin)
			{
				int sum = num[startout] + num[endoutTmp] + num[startin] + num[endin];
				vector<int> tmp;
				if(sum == target)
				{
					tmp.push_back(num[startout]);
					tmp.push_back(num[startin]);
					tmp.push_back(num[endin]);
					tmp.push_back(num[endoutTmp]);
					result.push_back(tmp);

					++startin;
					while(startin < endin && num[startin] == num[startin-1])
						++startin;

					--endin;
					while(startin < endin && num[endin] == num[endin+1])
						--endin;
				}
				else if(sum < target)
				{
					++startin;
					while(startin < endin && num[startin] == num[startin-1])
						++startin;
				}
				else
				{
					--endin;
					while(startin < endin && num[endin] == num[endin+1])
						--endin;
				}
			}
			--endoutTmp;
			while(startout < endoutTmp && num[endoutTmp] == num[endoutTmp+1])
				--endoutTmp;
		}
		++startout;
	}

	return result;
}

int main()
{
	int arr[] = {5,5,3,5,1,-5,1,-2};
	int target = 4;
	vector<int> num;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	vector<vector<int> > result = fourSum(num,target);

	for(int i=0; i<result.size(); ++i)
		cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << "\t" << result[i][3] << endl;
	return 0;
}
