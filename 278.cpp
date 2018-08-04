#include"common.h"
using namespace std;

bool isBadVersion(int version) {
    if(version<4) return false;
    return true;
}

int firstBadVersion(int n) {
    int start=1, end=n;
    while(start<=end) {
        int mid=start+(end-start)/2;
        if(isBadVersion(mid)) end=mid-1;
        else start=mid+1;
    }
    return end+1;
}

int main() {
    cout << firstBadVersion(5) << endl;
}
