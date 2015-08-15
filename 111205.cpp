#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

string convert(string s, int nRows)
{
	if(nRows == 1)
		return s;

	string result(s.size(),0);
	int pos = 0;

	for(int i=0; i<nRows; ++i)
	{
		int start = i;
		int end = i+(nRows-i-1)*2;
		while(1)
		{
			if(start >= s.size())
				break;

			if(start%(nRows-1) == 0)
				result[pos++] = s[start];
			else
			{
				result[pos++] = s[start];

				if(end >= s.size())
					break;
				result[pos++] = s[end];
			}

			start += 2*(nRows-1);
			end += 2*(nRows-1);
		}

		if(pos >= s.size())
			break;
	}
	return result;
}

int main()
{
//	string s = "PAYPALISHIRING";
	string s = "A";
	int nRows = 1;
	string result = convert(s, nRows);
	cout<<result<<endl;
	return 0;
}


