/* Paras Narang */
#include <iostream>
using namespace std;

int isPowerOfTwo (unsigned int x){
  return ((x != 0) && !(x & (x - 1)));
}

int main(){
    int num; cin >> num;
    isPowerOfTwo(num) ? cout << "True\n" : cout << "False\n";
    return 0;
}
