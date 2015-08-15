#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	vector<int> num_bk(numbers);
	stable_sort(numbers.begin(),numbers.end());

	vector<int>::iterator iter_begin = numbers.begin();
	vector<int>::iterator iter_end = numbers.end();
	--iter_end;

	while(1)
	{
		if(*iter_begin + *iter_end > target)
			--iter_end;
		else if(*iter_begin + *iter_end < target)
			++iter_begin;
		else
			break;
	}

	vector<int> result;
	for(vector<int>::iterator iter=num_bk.begin(); iter!=num_bk.end(); ++iter)
	{
		if(*iter == *iter_begin || *iter == *iter_end)
			result.push_back(iter-num_bk.begin()+1);
	}
	return result;
}

int main()
{
	vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
//	numbers.push_back(15);
	int target = 6;
	vector<int> result = twoSum(numbers,target);

	cout << result[0] << "\t" << result[1] << "\n";
	return 0;
}
