#include"common.h"
using namespace std;

int maxRotateFunction(vector<int>& A) {
    int total=accumulate(A.begin(), A.end(), 0);
    int res=0;
    for(int i=0; i<A.size(); ++i) res+=A[i]*i;
    int sum=res;
    for(int i=1; i<A.size(); ++i) {
        sum=sum+total-A.size()*A[A.size()-i];
        res=max(res, sum);
    }
    return res;
}

int main() {
    vector<int> A = {4, 3, 2, 6};
    cout << maxRotateFunction(A) << endl;
}
