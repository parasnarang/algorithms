/* Paras Narang */
#include <iostream>
using namespace std;

int GCD(int a, int b){
   if (b==0) return a;
   return GCD(b,a%b);
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a>b && a!=0) cout<<"GCD : "<<GCD(a,b);
    else cout<<"GCD : "<<GCD(b,a);
    return 0;
}