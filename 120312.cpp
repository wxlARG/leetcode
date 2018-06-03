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

string add(string num1, string num2)
{
	string result;
	int flag=0;
	int p=0,q=0,pos=0;

	while(p<num1.size() && q<num2.size())
	{
		int val1= num1[p++]-'0';
		int val2= num2[q++]-'0';

		int fin = val1+val2+flag;
		flag = fin/10;
		result.append(1,(fin%10)+'0');
	}

	while(p<num1.size())
	{
		int val1= num1[p++]-'0';
		int fin = val1+flag;
		flag = fin/10;
		result.append(1,(fin%10)+'0');
	}

	while(q<num2.size())
	{
		int val2= num2[q++]-'0';
		int fin = val2+flag;
		flag = fin/10;
		result.append(1,(fin%10)+'0');
	}

	if(flag != 0)
		result.append(1,flag+'0');

	return result;
}

string func(string num1, string num2)
{
	string result;
	if(num2.size()==1)
	{
		int base = num2[0]-'0';
		int flag = 0;
		int p=0;
		while(p<num1.size())
		{
			int val = num1[p]-'0';
			int fin = val*base+flag;
			flag = fin/10;
			result.append(1,(fin%10)+'0');
			++p;
		}

		while(flag != 0)
		{
			int fin = flag;
			flag /= 10;
			result.append(1,(fin%10)+'0');
		}
	}
	else
		result = add(func(num1,string(num2,0,1)), "0" + func(num1, string(num2,1,num2.size()-1)));

	return result;
}

string multiply(string num1, string num2)
{
	if(num1 == "0" || num2 == "0")
		return "0";

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	string result = func(num1,num2);
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string num1 = "1234567";
	string num2 = "0";
	string result = multiply(num1, num2);
	cout << result << endl;
	return 0;
}
