#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int myAtoi(string str) {
    int res = 0;
    int flag = 1;
    auto ptr = str.begin();
    while(*ptr == ' ') ++ptr;
    if(*ptr == '-' || *ptr == '+') {
        flag = *ptr == '-' ? -1 : 1;
        ++ptr;
    }

    for(; *ptr>='0' && *ptr<='9'; ++ptr) {
        int tmp = (*ptr-'0') * flag;
        if(flag > 0) {
            if(res > INT_MAX/10 || (res == INT_MAX/10 && tmp > INT_MAX%10)) return INT_MAX;
        } else {
            if(res < INT_MIN/10 || (res == INT_MIN/10 && tmp < INT_MIN%10)) return INT_MIN;
        }
        res = res * 10 + tmp;
    }
    return res;
}

int main() {
    cout << myAtoi("12345") << endl;
}
