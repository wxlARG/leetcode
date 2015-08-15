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

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area1 = (C-A) * (D-B);
	int area2 = (G-E) * (H-F);

	int tmpx=0,tmpy=0;

	if(C>E && E>=A)
		tmpx = min(G,C)-E;
	if(G>A && A>=E)
		tmpx = min(G,C)-A;

	if(H>B && B>=F)
		tmpy = min(D,H)-B;
	if(D>F && F>=B)
		tmpy = min(D,H)-F;

	return area1+area2-tmpx*tmpy;
}

int main()
{
	int result = computeArea(-3,0,3,4,0,-1,9,2);
	cout << result << endl;
	return 0;
}
