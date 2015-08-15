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

string intToRoman(int num)
{
	string charset[4];
	charset[0] = "IV";
	charset[1] = "XL";
	charset[2] = "CD";
	charset[3] = "M";

	string result;
	int pos = 0;
	while(num != 0)
	{
		int tmp = num % 10;
		num /= 10;

		if(tmp < 4)
		{
			for(int i=0; i<tmp; ++i)
				result.append(charset[pos],0,1);
		}
		else if(tmp == 4)
		{
			result.append(charset[pos],1,1);
			result.append(charset[pos],0,1);
		}
		else if(tmp < 9)
		{
			tmp -= 5;
			for(int i=0; i<tmp; ++i)
				result.append(charset[pos],0,1);
			result.append(charset[pos],1,1);
		}
		else
		{
			result.append(charset[pos+1],0,1);
			result.append(charset[pos],0,1);
		}

		++pos;
	}

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int num = 80;
	string result = intToRoman(num);
	cout<<result<<endl;
	return 0;
}


