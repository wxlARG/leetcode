#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for(int i=digits.size()-1; i>=0; --i) {
        digits[i] += carry;
        carry = digits[i]/10;
        digits[i] %= 10;
    }
    if(carry != 0) {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

int main() {
    vector<int> digits = {9, 9, 9};
    auto res = plusOne(digits);
    for(auto v: res) {
        cout << v << "\t";
    }
    cout << endl;
}
