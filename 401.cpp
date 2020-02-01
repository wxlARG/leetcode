#include"common.h"
using namespace std;

void helper(int num, int total, int cur, int val, int max, vector<int>& res) {
    if(num==0 && val<=max) {
        res.push_back(val);
        return;
    }
    if(cur>total || num>total-cur || val>max) return;
    helper(num-1, total, cur+1, val+(1<<cur), max, res);
    helper(num, total, cur+1, val, max, res);
}

vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for(int hour=0; hour<=4; ++hour) {
        for(int minute=0; minute<=6; ++minute) {
            if(hour+minute!=num) continue;
            vector<int> hours, minutes;
            helper(hour, 4, 0, 0, 11, hours);
            helper(minute, 6, 0, 0, 59, minutes);
            for(auto h: hours) {
                for(auto m: minutes) {
                    string tmp=to_string(h)+":";
                    if(m<10) tmp+="0";
                    tmp+=to_string(m);
                    res.push_back(tmp);
                }
            }
        }
    }
    return res;
}

int main() {
    auto vec = readBinaryWatch(2);
    for(auto s: vec) {
        cout << s << endl;
    }
}
