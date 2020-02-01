#include"common.h"
using namespace std;

vector<vector<int>> reconstructQueue_solution1(vector<vector<int>>& people) {
    vector<vector<int>> res;
    sort(people.begin(), people.end(), [](auto& a, auto& b){return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);});
    for(auto& p: people) res.insert(res.begin()+p[1], p);
    return res;
}

void helper(vector<vector<int>>& people, vector<int>& count, int start, int end) {
    if(start==end) return;
    int mid=start+(end-start)/2;
    helper(people, count, start, mid);
    helper(people, count, mid+1, end);
    int r=0;
    vector<vector<int>> tp;
    vector<int> tc;
    for(int p=start, q=mid+1; p<=mid || q<=end;) {
        if(p<=mid && q<=end) {
            if(count[p]-r>count[q]) {
                tp.push_back(people[q]);
                tc.push_back(count[q]);
                ++r;
                ++q;
            } else {
                tp.push_back(people[p]);
                tc.push_back(count[p]-r);
                ++p;
            }
        } else if(p<=mid) {
            tp.push_back(people[p]);
            tc.push_back(count[p]-r);
            ++p;
        } else {
            tp.push_back(people[q]);
            tc.push_back(count[q]);
            ++r;
            ++q;
        }
    }
    copy(tp.begin(), tp.end(), people.begin()+start);
    copy(tc.begin(), tc.end(), count.begin()+start);
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    if(people.empty()) return people;
    vector<int> count;
    sort(people.begin(), people.end(), [](auto& a, auto& b){return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);});
    for(auto& p: people) count.push_back(p[1]);
    helper(people, count, 0, people.size()-1);
    return people;
}

int main() {
    vector<vector<int>> people={{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    auto res = reconstructQueue(people);
    for(auto& v: res) cout << "[" << v[0] << ", " << v[1] << "]" << endl;
}
