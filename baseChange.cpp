/* Paras Narang */
#include <iostream>
using namespace std;

int toDecimal(int n, int b){
   int result=0;
   int multiplier=1;

   while(n>0){
      result+=n%10*multiplier;
      multiplier*=b;
      n/=10;
   }
   return result;
}

string fromDecimal(int n, int b){
   string chars="0123456789ABCDEFGHIJ";
   string result="";
      
   while(n>0){
      result=chars[n%b] + result;
      n/=b;
   }
   return result;
}

int main(){
    cout<<fromDecimal(50,8)<<endl;
    cout<<toDecimal(1101,2)<<endl;
    return 0;
}
