#include"common.h"
using namespace std;

int helper(int a, int b) {
    if(b<=2) return int(pow(a, b)) % 1337;
    if((b&1)!=0) return (helper(a, b-1)*a)%1337;
    return helper(helper(a, b>>1), 2);
}

int superPow(int a, vector<int>& b) {
    if(a>=1337) return superPow(a%1337, b);
    if(b.empty()) return 1;
    int right=helper(a, b.back());
    b.pop_back();
    int left=helper(superPow(a, b), 10);
    return (left*right)%1337;
}

int main() {
    vector<int> b={3, 4, 5};
    cout << superPow(2, b) << endl;
}
