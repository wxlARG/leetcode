#include"common.h"
using namespace std;

int computeArea_solution1(int A, int B, int C, int D, int E, int F, int G, int H) {
    int res=(C-A)*(D-B)+(G-E)*(H-F);
    int x=0, y=0;
    if(A<=E && E<C) x=min(G, C)-E;
    else if(E<A && A<G) x=min(G, C)-A;
    if(B<=F && F<D) y=min(D, H)-F;
    else if(F<B && B<H) y=min(D, H)-B;
    return res-x*y;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int res=(C-A)*(D-B)+(G-E)*(H-F);
    if(E>=C || A>=G || F>=D || B>=H) return res;
    return res-(min(C, G)-max(A, E))*(min(D, H)-max(B, F));
}

int main() {
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
}
