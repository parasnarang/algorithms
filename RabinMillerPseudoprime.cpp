/* Paras Narang */
// largest prime number less than input
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
#include <ctime>
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

ull num;

inline unsigned long long multi_mod(const unsigned long long &a,unsigned long long b,const unsigned long long &n)
{
    unsigned long long exp(a%n),tmp(0);
    while(b)
    {
        if(b&1)
        {
            tmp+=exp;
            if(tmp>n)
                tmp-=n;
        }
        exp<<=1;
        if(exp>n)
            exp-=n;
        b>>=1;
    }
    return tmp;
}

inline unsigned long long exp_mod(unsigned long long a,unsigned long long b,const unsigned long long &c)
{
    unsigned long long tmp(1);
    while(b)
    {
        if(b&1)
            tmp=multi_mod(tmp,a,c);
        a=multi_mod(a,a,c);
        b>>=1;
    }
    return tmp;
}

inline bool miller_rabbin(const unsigned long long &n,short T)
{
    if(n==2)
        return true;
    if(n<2 || !(n&1))
        return false;
    unsigned long long a,u(n-1),x,y;
    short t(0),i;
    while(!(u&1))
    {
        ++t;
        u>>=1;
    }
    while(T--)
    {
        a=rand()%(n-1)+1;
        x=exp_mod(a,u,n);
        for(i=0;i<t;++i)
        {
            y=multi_mod(x,x,n);
            if(y==1 && x!=1 && x!=n-1)
                return false;
            x=y;
        }
        if(y!=1)
            return false;
    }
    return true;
}

int main(){
    srand(time(NULL));
    int T; gint(T);
    while(T--){
        for(scanf("%llu",&num); !miller_rabbin(num,20); num--);
        printf("%llu\n",num);
    }
    return 0;
}
