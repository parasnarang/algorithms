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

#define MAXN 5000
int g[MAXN][MAXN],visited[MAXN],d[MAXN],p[MAXN];
int v,e;
void creategraph()
{
    int i,j,a,b,w;
    cout<<"\nVertices: ";
    cin>>v;
    cout<<"\nEdges ";
    cin>>e;
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
            g[i][j]=0;
    for(i=1;i<=v;i++)
    {
        p[i]=visited[i]=0;
        d[i]=oo;
    }
    for(j=1;j<=e;j++)
    {
        cout<<"\nEnter (a,b) and cost\n";
        cin>>a>>b>>w;
        g[a][b]=g[b][a]=w;
    }
}
void prim()
{
    ll current,totalvisited,mincost,i,min;
    current=1;
    d[current]=0;
    totalvisited=1;
    visited[current]=1;
    while(totalvisited!=v)
    {
        for(i=1;i<=v;i++)
        {
            if(g[current][i]!=0)
                if(visited[i]==0)
                    if(d[i]>g[current][i])
                    {
                        d[i]=g[current][i];
                        p[i]=current;
                    }
        }
        min=oo;
        for(i=1;i<=v;i++)
        {
            if(visited[i]==0)
            if(d[i]<min)
            {
                min=d[i];
                current=i;
            }
        }
        visited[current]=1;
        totalvisited++;
    }
    mincost=0;
    for(i=0;i<=v;i++)
        mincost+=d[i];
    cout<<"\nMin cost ="<<mincost;
    cout<<"\nMin span Tree: ";
    for(int i=2;i<=v;i++)
        cout<<"\nVertex "<<i<<" is connected to "<<p[i];
}
int main()
{
    int i;
    creategraph();
    prim();
    return 0;
}
