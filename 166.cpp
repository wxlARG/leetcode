#include"common.h"
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    string res;
    if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)) res += "-";
    long long num=abs((long long)numerator), den=abs((long long)denominator);
    res+=to_string(num/den);
    num %= den;
    if(num==0) return res;
    res += ".";
    unordered_map<long long, long long> mapping;
    while(num!=0 && mapping.find(num)==mapping.end()) {
        mapping[num]=res.size();
        num*=10;
        res += to_string(num/den);
        num %= den;
    }
    if(num!=0) {
        res.insert(mapping[num], "(");
        res += ")";
    }
    return res;
}

int main() {
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(2, 1) << endl;
    cout << fractionToDecimal(2, 3) << endl;
    cout << fractionToDecimal(-50, 8) << endl;
    cout << fractionToDecimal(INT_MIN, -1) << endl;
}
