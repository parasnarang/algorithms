/* Paras Narang 
 * Josephus Problem
 * http://en.wikipedia.org/wiki/Josephus_problem
 * */
#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    int res = 1;
      for (int i=2; i<=n; i++)
        res = (res + k - 1) % i + 1;
    return res;
}

int main(){
    int M,N;
    cin>>M>>N;
    printf("%d\n", josephus(M, N));
    return 0;
}
