/* Paras Narang */
#include <iostream>
using namespace std;

int GCD(int a, int b){
   if (b==0) return a;
   return GCD(b,a%b);
}

int LCM(int a, int b){
   return b*a/GCD(a,b);
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a>b && a!=0) cout<<"LCM : "<<LCM(a,b);
    else cout<<"LCM : "<<LCM(b,a);
    return 0;
}
