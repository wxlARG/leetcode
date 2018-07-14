#include"common.h"
using namespace std;

bool isUgly(int num) {
    if(num==0) return false;
    while(num%5==0) num/=5;
    while(num%3==0) num/=3;
    while((num&1)==0) num>>=1;
    return num==1;
}

int main() {
    cout << isUgly(1) << endl;
    cout << isUgly(6) << endl;
    cout << isUgly(8) << endl;
    cout << isUgly(14) << endl;
}
