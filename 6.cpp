#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string convert(string s, int numRows) {
    if(numRows<=1)
        return s;
    string res(s.size(), 0);
    for(int i=0, pos=0; i<numRows; ++i) {
        for(int j=i, step=1; j<s.size(); ++step) {
            res[pos++] = s[j];
            if(i==0)
                j = 2*step*(numRows-1);
            else if(i==numRows-1) 
                j = (2*step+1)*(numRows-1);
            else {
                if(step & 1) j = (step+1)*(numRows-1) - i;
                else j = step*(numRows-1) + i;
            }
        }
    }
    return res;
}

int main() {
    cout << convert("PAYPALISHIRING", 3) << endl;
}
