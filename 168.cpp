#include"common.h"
using namespace std;

string convertToTitle(int n) {
    string res;
    while(n) {
        res.push_back((n-1)%26+'A');
        n=(n-1)/26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << convertToTitle(1) << endl;
    cout << convertToTitle(28) << endl;
    cout << convertToTitle(701) << endl;
    cout << convertToTitle(676) << endl;
}
