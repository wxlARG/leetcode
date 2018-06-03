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

vector<string> letterCombinations(string digits)
{
	string str[10];
	str[2] = "abc";
	str[3] = "def";
	str[4] = "ghi";
	str[5] = "jkl";
	str[6] = "mno";
	str[7] = "pqrs";
	str[8] = "tuv";
	str[9] = "wxyz";
	deque<string> queue;

	for(string::iterator iter=digits.begin(); iter!=digits.end(); ++iter)
	{
		int num = *iter-'0';
		if(queue.empty())
		{
			for(int i=0; i<str[num].size(); ++i)
				queue.push_back(string(1,str[num][i]));
		}
		else
		{
			int size = queue.front().size();
			while(queue.front().size() == size)
			{
				string strbk = queue.front();
				queue.pop_front();
				for(int i=0; i<str[num].size(); ++i)
				{
					string tmpStr = strbk;
					tmpStr.append(1,str[num][i]);
					queue.push_back(tmpStr);
				}
			}
		}
	}

	vector<string> result(queue.begin(),queue.end());
	if(result.empty())
		result.push_back("");
	return result;
}

int main()
{
	string digits = "23";
	vector<string> result = letterCombinations(digits);

	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
