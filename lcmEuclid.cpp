/* Paras Narang */
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

int GCD(int a, int b)
{
   if (b==0)
     return a;
   return GCD(b,a%b);
}

int LCM(int a, int b)
{
   return b*a/GCD(a,b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b && a!=0)
      cout<<"LCM : "<<LCM(a,b);
    else
      cout<<"LCM : "<<LCM(b,a);
    return 0;
}
