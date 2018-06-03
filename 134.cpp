#include"common.h"
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start=0, r=0;
    for(int pos=0; start<int(gas.size()) && pos-start<gas.size(); ++pos) {
        r+=gas[pos%gas.size()]-cost[pos%cost.size()];
        if(r<0) {
            start=pos+1;
            r=0;
        }
    }
    return start<int(gas.size())? start: -1;
}

int main() {
    vector<int> gas={4,1};
    vector<int> cost={5,0};
    cout << canCompleteCircuit(gas, cost) << endl;
}
