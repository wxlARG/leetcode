#include"common.h"
using namespace std;

int candy_solution1(vector<int>& ratings) {
    ratings.push_back(ratings.back());
    int res=0, last=0;
    for(int i=0; i<ratings.size()-1; ++i) {
        if(ratings[i]<ratings[i+1]) {
            ++last;
            res+=last;
        } else if(ratings[i]==ratings[i+1]) {
            res+=last+1;
            last=0;
        } else {
            int len=1;
            for(; i<ratings.size()-1 && ratings[i]>ratings[i+1]; ++i) ++len;
            if(last+1>len) res += last+1+(len-1)*len/2;
            else res += len*(len+1)/2;
            if(i<ratings.size()-1 && ratings[i]==ratings[i+1]) last=0;
            else last=1;
        }
    }
    return res;
}

int candy(vector<int>& ratings) {
    int up=0, down=0, res=0;
    int slop=0;
    for(int i=1; i<ratings.size(); ++i) {
        int tmp_slop=0;
        if(ratings[i]>ratings[i-1]) tmp_slop=1;
        else if(ratings[i]<ratings[i-1]) tmp_slop=-1;
        if((slop<=0 && tmp_slop>=0) || (slop>0 && tmp_slop==0)) {
            res+=up*(up+1)/2 + down*(down+1)/2 + max(up, down);
            up=down=0;
        }
        if(tmp_slop>0) ++up;
        else if(tmp_slop<0) ++down;
        else ++res;
        slop=tmp_slop;
    }
    res+=up*(up+1)/2 + down*(down+1)/2 + max(up, down)+1;
    return res;
}

int main() {
    //vector<int> ratings={1, 3, 2};
    //vector<int> ratings={5, 1, 1, 1, 10, 2, 1, 1, 1, 3};
    vector<int> ratings={1,2,87,87,87,2,1};
    cout << candy(ratings) << endl;
}
