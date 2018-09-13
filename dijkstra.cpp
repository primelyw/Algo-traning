#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e4;
int d[maxn];
typdef pair<int,int>P;
const int oo = 1e9;
struct edge{
    int to,cost;
    edge(int x,int y):to(x),cost(y){}
};
vector<edge> G[N];

void dijkstra(int s){
    fill(d,d+maxn+1,oo);
    d[s] = 0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
		if(d[v]<p.first) continue;
        for(int i = 0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
