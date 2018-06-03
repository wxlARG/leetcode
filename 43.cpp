#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string multiply_one(string num1, int c) {
    if(c==0) return "0";
    string res;
    for(int i=0, p=0; i<num1.size() || p; ++i) {
        int v = (i<num1.size()? (num1[i]-'0'): 0)*c+p;
        res += v%10+'0';
        p=v/10;
    }
    return res;
}

string add_num(string num1, string num2) {
    string res;
    for(int i=0, p=0; i<max(num1.size(), num2.size()) || p; ++i) {
        int v = (i<num1.size()? (num1[i]-'0'): 0) + (i<num2.size()? (num2[i]-'0'): 0) + p;
        res += v%10+'0';
        p = v/10;
    }
    return res;
}

string multiply_solution1(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string res;
    for(int i=0; i<num2.size(); ++i) {
        string tmp = multiply_one(num1, num2[i]-'0');
        if(tmp.size()==1 && tmp[0] == '0') tmp = "0";
        else tmp = string(i, '0')+tmp;
        res = add_num(res, tmp);
    }
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string num1, string num2) {
    string res(num1.size()+num2.size(), '0');
    for(int i=num1.size()-1; i>=0; --i) {
        int carry = 0;
        for(int j=num2.size()-1; j>=0; --j) {
            int v = (res[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
            res[i+j+1] = v%10+'0';
            carry = v/10;
        }
        res[i] += carry;
    }
    auto it = res.find_first_not_of('0');
    if(it==string::npos) return "0";
    return res.substr(it);
}

int main() {
    //cout << multiply("12345", "54321") << endl;
    cout << multiply("12345", "0") << endl;
}
