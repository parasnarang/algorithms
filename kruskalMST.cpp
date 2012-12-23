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

//Union set data structure
#define mx 10005
class unionfind
{
    int parent[mx], rank[mx];
  public:
    unionfind(int n)
    {
        for(int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x) 
    {
        if(parent[x] != x) parent[x] = root(parent[x]);
        return parent[x];
    }

    void merge(const int &a, const int &b) 
    {
        int ra = root(a), rb = root(b);
        if(ra == rb) return;

        if(rank[ra] > rank[rb]) parent[rb] = ra;
        else parent[ra] = rb;
        if(rank[ra] == rank[rb]) rank[rb]++;
        return;
    }
};
//Union set data structure ends

struct Edge
{
    int from, to, weight;
    Edge(int f = 0, int t = 0, int w = 0) : from(f), to(t), weight(w) {}
    bool operator<(Edge other) const
    {
        return weight < other.weight;
    }
};

vector<Edge> e;
vector<Edge> mst;
int n=0,v=0; //n = nodes/vertices ; v = edges

void creategraph()
{
    gint(n);
    //Every vertex connected to every other vertex
    v = (n-1)*n/2;
    REP(vi,v)
    {
      int a,b,cost;
      cin>>a>>b>>cost;
      Edge e1(a,b,cost);
      e.pb(e1);
    }
}

void krushkal()
{
    unionfind list(n);
    sort(e.begin(), e.end());
    REP(vi,v)
    {
      int f = e[vi].from;
      int t = e[vi].to;
      if(list.root(f) == list.root(t))
          continue;
      else
      {
        list.merge(f,t);
        mst.pb(e[vi]);
      }
    }
}

void showgraph(vector<Edge> vec)
{
    int i=0;
    EACH(it,vec)
    {
      cout<<vec[i].from<<" "<<vec[i].to<<" "<<vec[i].weight<<endl;
      i++;
    }
}

int main()
{
    creategraph();
    showgraph(e);
    krushkal();
    cout<<" MST \n";
    showgraph(mst);
    return 0;
}
