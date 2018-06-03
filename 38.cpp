#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string countAndSay(int n) {
    if(n<=0)
        return string();
    string res = "1";
    while(--n) {
        string tmp;
        int count = 1;
        for(int i=1; i<res.size(); ++i) {
            if(res[i]==res[i-1]) {
                ++count;
            } else {
                tmp.push_back(count+'0');
                tmp.push_back(res[i-1]);
                count = 1;
            }
        }
        tmp.push_back(count+'0');
        tmp.push_back(res.back());
        res = tmp;
    }
    return res;
}

int main() {
    cout << countAndSay(1) << endl;
}
