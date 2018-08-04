#include"common.h"
using namespace std;

string getHint(string secret, string guess) {
    vector<int> s(10, 0), g(10, 0);
    int countA=0, countB=0;
    for(int i=0; i<secret.size(); ++i) {
        if(secret[i]==guess[i]) {
            ++countA;
        } else {
            ++s[secret[i]-'0'];
            ++g[guess[i]-'0'];
        }
    }
    for(int i=0; i<10; ++i) countB += min(s[i], g[i]);
    return to_string(countA)+"A"+to_string(countB)+"B";
}

int main() {
    cout << getHint("1807", "7810") << endl;
    cout << getHint("1123", "0111") << endl;
}
