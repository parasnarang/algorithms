/* Paras Narang 
 * Program to count number of prime numbers below n using sieve of Eratosthenes
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

#define oo 0x7F7F7F7F
#define LET(x,a)     __typeof(a) x(a)
#define EACH(it,v)   for(LET(it,v.begin());it!=v.end();++it)
#define REP(i,n)     for(__typeof(n) i(0); i<n; i++)
#define FOR(i,j,n)   for(__typeof(n) i(j); i<n; i++)
#define ALL(x)       (x).begin(), (x).end()
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back
#define mp           make_pair

typedef long long int   ll;
typedef unsigned long long int ull;
typedef unsigned int    uint;
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<pii>     vpii;

#define MaxNum 200000
int numPrimes[MaxNum+5];
int countPrimes(int n){
    int sievesize = n;
    vector<int, allocator<int> > sieve ((size_t)sievesize, 1);

    for (int i = 2; i * i < sievesize; i++)
        if (sieve[i])
            for (int j = i + i; j < sievesize; j += i)
                sieve[j] = 0;

    numPrimes[0] = 0;
    numPrimes[1] = 0;
    int count = 0;
    for (int j = 2; j < sievesize; j++){
        if (sieve[j]){
            count++;
        }
        numPrimes[j]=count;
    }
}

void preprocess(){
    countPrimes(MaxNum);
}

int main() {
    preprocess();
    int t; gint(t);
    REP(ti, t) {
        int n; gint(n);
        int res = numPrimes[n];
        printf("%d\n", res);
    }
    return 0;
}

