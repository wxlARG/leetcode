#include"common.h"
using namespace std;

int hIndex_solution1(vector<int>& citations) {
    int pos=-1, size=citations.size();
    for(int start=0, end=citations.size()-1; start<=end; ) {
        int mid=start+(end-start)/2;
        if(size-mid>citations[mid]) start=mid+1;
        else if(size-mid==citations[mid]) return size-mid;
        else {
            if(mid==start || citations[mid-1]<=size-mid) pos=mid;
            end=mid-1;
        }
    }
    return pos==-1? 0: size-pos;
}

int hIndex(vector<int>& citations) {
    int start=0, end=citations.size()-1, len=citations.size();
    while(start<=end) {
        int mid=start+(end-start)/2;
        if(citations[mid]>=len-mid) end=mid-1;
        else start=mid+1;
    }
    return len-(end+1);
}

int main() {
    //vector<int> citations={0,1,3,5,6};
    vector<int> citations={0,1,3,5,6,7,8};
    cout << hIndex(citations) << endl;
}
