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
 
#define MAXN 1005

int main()
{
    int minC[MAXN];
    int n,res=0;
    gint(n);
    
    // If Multiple values for which minimum number of coins need to be found
    //vi q;
    //REP(ni,n) 
    //{
        //int x;
        //gint(x);
        //q.push_back(x);
    //}
    
    // If Single value
    int q;
    gint(q);

    // Initialize all MinCoins to infinity
    REP(ni, MAXN)
      minC[ni]=oo;
    // MinCoins[0] is 0
    minC[0] = 0;
    // Store the value of each coin in num and modify MinCoins array accordingly
    REP(ni, n)
    {
        int num;
        gint(num);
        for(int i=0; i<=MAXN-num; i++)
        {
            minC[i+num] = min(minC[i+num], minC[i]+1);
        }
    }
    
    // Calculating for Multiple values
    //REP(ni, n) 
        //res+=minC[q[ni]];

    // Calculating for single value
    res = minC[q];

    // Print the minimum number of coins required
    printf("%d\n",res);

    return 0;
}
