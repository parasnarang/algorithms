/* Paras Narang 
 *
 * Bellman Ford Algorithm
 * */
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

int N_MAX = 7;

struct Edge{
    Edge(int _from, int _to, int _w){
        from = _from;
        to = _to;
        w = _w;
    }

    bool operator <(const Edge& b) const{
        return w < b.w;
    }

    bool operator >(const Edge& b) const{
        return b.w < w;
    }

    int from;
    int to;
    int w;
};

vector<Edge> edges;
vector<int> distances(N_MAX);
int num_vertices, num_edges, from, to, weight;

void bellman_ford(){
    fill(distances.begin(), distances.end(), 10000);
    distances[0] = 0;

    for(int i = 0; i < num_vertices - 1; ++i){
        for(int i = 0; i < edges.size(); ++i){
            if(distances[edges[i].to] > distances[edges[i].from] + edges[i].w)
                distances[edges[i].to] = distances[edges[i].from] + edges[i].w;

            if(distances[edges[i].from] > distances[edges[i].to] + edges[i].w)
                distances[edges[i].from] = distances[edges[i].to] + edges[i].w;
        }
    }

    for(int i = 0; i < num_vertices; ++i)
        cout << "Distance to " << i << " is " << distances[i] << endl;
}


void creategraph(){
    cin >> num_vertices;
    cin >> num_edges;
    for(int j = 0; j < num_edges; ++j){
      cin >> from >> to >> weight;
      edges.push_back(Edge(from, to, weight));
    }
}

int main(){
    creategraph();
    bellman_ford();
    return 0;
}
