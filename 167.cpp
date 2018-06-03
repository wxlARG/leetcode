#include"common.h"
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int start=0, end=numbers.size()-1;
    vector<int> res;
    while(start<end) {
        if(numbers[start]+numbers[end]<target) {
            ++start;
        } else if(numbers[start]+numbers[end]>target) {
            --end;
        } else {
            res={start+1, end+1};
            break;
        }
    }
    return res;
}

int main() {
    vector<int> numbers = {2,7,11,15};
    auto res = twoSum(numbers, 9);
    for(auto &v: res) cout << v << "\t";
    cout << endl;
}
