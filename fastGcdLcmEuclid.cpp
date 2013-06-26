/* Paras Narang */
#include <iostream>
using namespace std;

int GCD(int a, int b){
    while(b>0){
        a = a%b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int LCM(int a, int b){
   return b*a/GCD(a,b);
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << "LCM : " << LCM(a,b);
    return 0;
}
