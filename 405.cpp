#include"common.h"
using namespace std;

string toHex(int num) {
    string res;
    char* ptr=(char*)&num;
    for(int i=3; i>=0; --i) {
        auto upper=(ptr[i]&0xf0)>>4, lower=ptr[i]&0x0f;
        if(upper!=0 || !res.empty()) {
            if(upper<10) res+=to_string(upper);
            else res+=(upper-10)+'a';
        } 
        if(lower!=0 || !res.empty()) {
            if(lower<10) res+=to_string(lower);
            else res+=(lower-10)+'a';
        }
    }
    return res.empty()? "0": res;
}

int main() {
    cout << toHex(26) << endl;
    cout << toHex(-1) << endl;
}
