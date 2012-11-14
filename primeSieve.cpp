/* Paras Narang */
// Sieve of Eratosthenes to find primes
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

int main()
{
    int n;
    cin>>n;
    vector<bool> prime (n+1);

    // Set all to true
    EACH(it,prime)
      *it=true;

    prime[0]=false;
    prime[1]=false;
    int m=sqrt(n);

    for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=false;

    // Display Elements
    for(int i=2;i<=n;i++)
      if(prime[i])
        cout<<i<<endl;
    return 0;
}
