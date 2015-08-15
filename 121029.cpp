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

int minimumTotal(vector<vector<int> > &triangle)
{
	vector<int> cache(triangle.size(),0);
	int result = INT_MAX;

	for(int i=0; i<triangle.size(); ++i)
	{
		int last = INT_MAX;
		for(int j=0; j<triangle[i].size(); ++j)
		{
			int tmp = cache[j];

			if(j==0)
				cache[j] += triangle[i][j];
			else if(j==triangle[i].size()-1)
				cache[j] = triangle[i][j] + last;
			else
				cache[j] = triangle[i][j] + min(last,cache[j]);

			last = tmp;

			if(i==triangle.size()-1 && result>cache[j])
				result = cache[j];
		}
	}
	return result;
}

int main()
{
	vector<vector<int> > triangle;
	vector<int> row;

	row.push_back(2);
	triangle.push_back(row);

	row.clear();
	row.push_back(3);
	row.push_back(4);
	triangle.push_back(row);

	row.clear();
	row.push_back(6);
	row.push_back(5);
	row.push_back(7);
	triangle.push_back(row);

	row.clear();
	row.push_back(4);
	row.push_back(1);
	row.push_back(8);
	row.push_back(3);
	triangle.push_back(row);

	int result = minimumTotal(triangle);
	cout << result << endl;
	return 0;
}
