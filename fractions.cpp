/* Paras Narang */
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>     vi;

int GCD(int a, int b){
    if (b==0) return a;
    return GCD(b,a%b);
}

int LCM(int a, int b){
    return b*a/GCD(a,b);
}

vi multiplyFractions(vi a, vi b){
    vi c (2);
    c[0]= a[0]*b[0];
    c[1]= a[1]*b[1];
    return c;
}

vi addFractions(vi a, vi b){
    int denom=LCM(a[1],b[1]);
    vi c(2);
    c[0] = denom/a[1]*a[0] + denom/b[1]*b[0] ;
    c[1] = denom;
    return c;
}

vi reduceFraction(vi a){
    int b=GCD(a[0],a[1]);
    a[0]/=b;
    a[1]/=b;
    return a;
}

vi multiplyComplex(vi m, vi n){
    vi prod(2);
    prod[0] = m[0]*n[0] - m[1]*n[1];
    prod[1] = m[0]*n[1] + m[1]*n[0];
    return prod;
}

int main(){
    vi a(2);
    a[0]=12,a[1]=24;
    vi b(2);
    b = reduceFraction(a);
    cout<<b[0]<<"/"<<b[1]<<endl;

    return 0;
}