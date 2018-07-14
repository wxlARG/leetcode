#include"common.h"
using namespace std;

unordered_map<int, string> mapping = {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, 
    {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, 
    {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, 
    {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
    {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, 
    {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, 
    {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
};

void helper(int num, int suffix, vector<string>& cache) {
    if(num==0) return;
    helper(num/1000, suffix*1000, cache);
    int n=num%1000;
    if(n==0) return;
    if(n>=100) {
        cache.push_back(mapping[n/100]);
        cache.push_back(mapping[100]);
    }
    n%=100;
    if(n!=0 && n<=20) {
        cache.push_back(mapping[n]);
    } else if(n!=0) {
        cache.push_back(mapping[n/10*10]); 
        if(n%10!=0) cache.push_back(mapping[n%10]);
    }
    if(suffix!=1) cache.push_back(mapping[suffix]);
    return;
}

string numberToWords(int num) {
    if(num==0) return mapping[num];
    vector<string> cache;
    string res;
    helper(num, 1, cache);
    for(auto& str: cache) res+=str+" ";
    res.pop_back();
    return res;
}

int main() {
    cout << numberToWords(30) << endl;
    cout << numberToWords(123) << endl;
    cout << numberToWords(12345) << endl;
    cout << numberToWords(1234567) << endl;
    cout << numberToWords(1234567891) << endl;
}
