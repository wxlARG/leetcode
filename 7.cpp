#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int reverse(int x) {
    int res = 0;
    int flag = (x<0 ? -1 : 1);
    while(x!=0) {
        if(flag > 0) {
            if(res > INT_MAX/10 || (res == INT_MAX/10 && x > INT_MAX%10)) return 0;
        } else {
            if(res < INT_MIN/10 || (res == INT_MIN/10 && x < INT_MIN%10)) return 0;
        }
        
        int tmp = x%10;
        x /= 10;
        res = res * 10 + tmp;
    }
    return res;
}

int main() {
    cout << reverse(INT_MIN) << endl;
}
