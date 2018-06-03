#include"common.h"
using namespace std;

int compareVersion(string version1, string version2) {
    size_t i=0, j=0;
    for(;; ++i, ++j) {
        auto ni=version1.find_first_of(".", i);
        auto nj=version2.find_first_of(".", j);
        if(stoi(version1.substr(i, ni-i))<stoi(version2.substr(j, nj-j))) return -1;
        else if(stoi(version1.substr(i, ni-i))>stoi(version2.substr(j, nj-j))) return 1;
        i=ni, j=nj;
        if(ni==string::npos || nj==string::npos) break;
    }
    if(i==string::npos && j==string::npos) return 0;
    if(i!=string::npos) {
        for(; i<version1.size(); ++i)
            if(version1[i]!='0' && version1[i]!='.') return 1;
    } else {
        for(; j<version2.size(); ++j)
            if(version2[j]!='0' && version2[j]!='.') return -1;
    }
    return 0;
}

int main() {
    cout << compareVersion("0.1", "1.1") << endl;
    cout << compareVersion("1.0.1", "1") << endl;
    cout << compareVersion("7.5.2.4", "7.5.3") << endl;
    cout << compareVersion("01", "1") << endl;
    cout << compareVersion("1", "1.1") << endl;
}
