#include"common.h"
using namespace std;

string add(string& num, pair<int, int> p1, pair<int, int> p2) {
    string res;
    int carry=0;
    for(int i=p1.second, j=p2.second; i>=p1.first || j>=p2.first || carry!=0; --i,--j) {
        int val=carry+(i>=p1.first? num[i]-'0': 0)+(j>=p2.first? num[j]-'0': 0);
        carry=val/10;
        res.push_back('0'+val%10);
    }
    reverse(res.begin(), res.end());
    return res;
}

bool valid(string& num, pair<int, int> p1, pair<int, int> p2) {
    do {
        if(p1.second-p1.first>0 && num[p1.first]=='0') return false;
        if(p2.second-p2.first>0 && num[p2.first]=='0') return false;
        auto s3=add(num, p1, p2);
        if(s3.size()>num.size()-p2.second-1) return false;
        if(num.compare(p2.second+1, s3.size(), s3)!=0) return false;
        p1=p2;
        p2={p2.second+1, p2.second+s3.size()};
    } while(p2.second!=num.size()-1);
    return true;
}

bool isAdditiveNumber(string num) {
    for(int i=1; i<num.size(); ++i) {
        for(int j=0; j<i; ++j) {
            pair<int, int> p1({0, j}), p2({j+1, i});
            if(valid(num, p1, p2)) return true;
        }
    }
    return false;
}

int main() {
    cout << isAdditiveNumber("112358") << endl;
    cout << isAdditiveNumber("199100199") << endl;
    cout << isAdditiveNumber("199001200") << endl;
}
