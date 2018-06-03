#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0 || (x > 0 && x % 10 == 0)) return false;
    int n = 0;
    while(x != 0) {
        n = n*10 + x % 10;
        if(n == x) return true;
        x /= 10;
        if(n == x) return true;
        if(x < n) return false;
    }
    return true;
}

int main() {
    cout << isPalindrome(0) << endl;
}
